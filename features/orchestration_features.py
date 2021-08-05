import threading
import logging
import multiprocessing.pool
import multiprocessing
import concurrent.futures

import core.filesystem
import core.function
import core.pe
import compare.compare_pe
import compare.compare_function
import core.exceptions


class OrchestrationFeatures(object):
    def __init__(self, iterators, configurations, is_ordered_orchestration=False):
        """

        :param iterators:
        :param configurations:
        :param is_ordered_orchestration: if this variable is true it can't run parallel and will require much more RAM
                                         for feature with dependencies
        """
        self.configurations = configurations
        self.iterators = iterators
        if is_ordered_orchestration:
            self.execute_result = self.ordered_execute_result
            self.orchestration_pe_versions = self.ordered_orchestration_pe_versions
        else:
            self.execute_result = self.unordered_execute_result
            self.orchestration_pe_versions = self.unordered_orchestration_pe_versions

    def _reduce_pes(self, exec_versions):
        temp_exec_version = []
        ignore_list = self.configurations.configs.orchestration.ignore_list
        for exec_version in exec_versions:
            if exec_version.name in ignore_list:
                continue
            temp_exec_version.append(exec_version)

        return temp_exec_version

    def _reduce_groups(self, reduced_groups):
        return reduced_groups

    def compare_to_key(self, compare1, all_pes):
        """
         Get compare object and return a comparable value so we can sort the groups and finish working on files.
         :param all_pes: list of all the versions of a PE (list of PE objects) ordered by version. ordered.
         :param compare1: compare.compare object
         :return: PE
         """
        min_pe_ver = None  # minimal version, no ida required.
        for obj_to_compare in compare1.objects_to_compare:
            if obj_to_compare is None:
                continue

            if min_pe_ver is None or min_pe_ver.version > obj_to_compare.version:
                min_pe_ver = obj_to_compare

        if min_pe_ver is None:
            return None

        # To support ADDED or REMOVED we need to find the second minimum in case of None.
        if None in compare1.objects_to_compare:
            min_index = 0
            for index, current_pe in enumerate(all_pes):
                if current_pe.version == min_pe_ver.version:
                    min_index = index
                    break

            if min_index == 0:
                return all_pes[0]
            return all_pes[min_index - 1]  # the compare might be related to added or removed PE.

        return min_pe_ver

    @staticmethod
    def pop_smallest_element(queue, comparable_index):
        min_index = 0
        if len(queue) == 0:
            raise ValueError("queue expected to be not empty")

        for index, elements in enumerate(queue):
            if elements[comparable_index] is None:
                min_index = index
                break
            if queue[min_index][comparable_index] is None and elements[comparable_index] is not None:
                min_index = index  # should not reach here but for validation
            if queue[min_index][comparable_index].version > elements[comparable_index].version:
                min_index = index

        return queue.pop(min_index)

    @staticmethod
    def close_not_required_pes(queue, pes, comparable_index):
        minimal_version_required = None
        for elemets in queue:
            if elemets[comparable_index] is None:
                return
            elif minimal_version_required is None:  # elemets[comparable_index]
                minimal_version_required = elemets[comparable_index]
            elif minimal_version_required.version > elemets[comparable_index].version:
                minimal_version_required = elemets[comparable_index]

        for pe in pes:
            if pe.version < minimal_version_required.version:
                pe.disconnect_connections()

    def ordered_orchestration_pe_versions(self, executable_versions):
        """
        ordered orchestration on PEs, It wont run parallel because it returns a generator.
        :param executable_versions: list of executables
        :return: generator of Result objects
        """
        list_executable_versions = list(executable_versions)  # make sure it is not generator.
        reduced_exes = self._reduce_pes(list_executable_versions)
        logging.info(f"began processing {list_executable_versions} {threading.get_ident()}")
        for feature in self.iterators:
            groups = feature.group_by.group_by(list_executable_versions, reduced_exes)
            reduced_groups = self._reduce_groups(groups)
            for reduced_group in reduced_groups:
                try:
                    yield feature.iterate(reduced_group)
                except KeyboardInterrupt:
                    raise
                except Exception as e:
                    message = ""
                    try:
                        message = str(list_executable_versions)  # Safer way to access it.
                    except Exception:
                        pass
                    logging.critical(f"Orchestration failed {e}, {message}", exc_info=True)

        for pe in list_executable_versions:
            pe.disconnect_connections()

        logging.info(f"finished processing {list_executable_versions}")

    def unordered_orchestration_pe_versions(self, executable_versions):
        list_executable_versions = list(executable_versions)  # make sure it is not generator.
        list_executable_versions.sort(key=lambda x: x.version)  # ordered PEs
        reduced_exes = self._reduce_pes(list_executable_versions)
        logging.info(f"began processing {list_executable_versions} {threading.get_ident()}")
        queue = []
        for feature in self.iterators:
            groups = feature.group_by.group_by(list_executable_versions, reduced_exes)
            reduced_groups = self._reduce_groups(groups)
            queue.append((reduced_groups, feature, None))

        while len(queue) > 0:
            try:
                reduced_groups, feature, minimal_required = type(self).pop_smallest_element(queue, 2)
                is_finished_iterating = True
                for reduced_group in reduced_groups:
                    yield feature.iterate(reduced_group)
                    current_version_required = self.compare_to_key(reduced_group, list_executable_versions)
                    if minimal_required is None:
                        minimal_required = current_version_required
                    elif current_version_required is not None and current_version_required.version > minimal_required.version:
                        is_finished_iterating = False
                        minimal_required = current_version_required
                        break

                if not is_finished_iterating:
                    # push back to update minimal_required
                    queue.append((reduced_groups, feature, minimal_required))
                    type(self).close_not_required_pes(queue, list_executable_versions, 2)

            except KeyboardInterrupt:
                raise
            except Exception as e:
                message = ""
                try:
                    # In order to not miss the rest of the executions.
                    queue.append((reduced_groups, feature, minimal_required))
                    message = str(list_executable_versions)  # Safer way to access it.
                except Exception:
                    pass
                logging.critical(f"Orchestration failed {e}, {message}", exc_info=True)

        # it should be list_executable_versions and not reduced_exes because even that some pes were reduced they might
        # be still got selected and used.
        for pe in list_executable_versions:
            pe.disconnect_connections()

        logging.info(f"finished processing {list_executable_versions}")

    def unordered_execute_result(self, pe_versions_thread):
        """
        DO NOT CONVERT IT TO GENERATOR, IT WILL NOT RUN IN PARALLEL!
        :param pe_versions_thread: list of pes to compare
        :return: list of scores
        """
        scores = []
        for i in self.ordered_execute_result(pe_versions_thread):
            scores.append(i)
        return scores

    def ordered_execute_result(self, pe_versions_thread):
        """
        DO NOT CONVERT IT TO GENERATOR, IT WILL NOT RUN IN PARALLEL!
        :param pe_versions_thread: list of pes to compare
        :return: list of scores
        """
        max_retries = self.configurations.configs.orchestration.max_pe_group_retries
        current_retries = 0
        try:
            for thread_feature_scores in self.orchestration_pe_versions(pe_versions_thread):
                try:
                    for thread_score in thread_feature_scores:
                        yield thread_score
                except core.exceptions.FailedToDecompile as ex:  # feature failed to decompile function
                    logging.warning(f"Failed to decompile PE {ex.args}")
                except core.exceptions.IntegrationTimeout as ex:
                    logging.warning(f"Failed to connect to Ida {ex.args}")
                    current_retries += 1
                    if current_retries > max_retries:
                        raise
                except TimeoutError as e:
                    logging.warning(f"Waited too much time for a response in {e.args}", exc_info=True)
                    current_retries += 1
                    if current_retries > max_retries:
                        raise
                except Exception as int_ex:
                    logging.critical(f"Orchestration3 internal failed reached max retries, catching {int_ex}",
                                     exc_info=True)

        except core.exceptions.IntegrationTimeout as ex:
            logging.error(f"Integration failed due timeout {ex}")
        except Exception as ex:
            logging.critical(f"Orchestration3 failed {ex}", exc_info=True)

    def orchestrate_all(self, filesystem):
        # because we're doing a loop if it will be a generator it will work only once.
        all_filesystem = filesystem.get_all_files_group_by_executable_type()
        number_of_threads = self.configurations.configs.orchestration.parallel_threads
        if number_of_threads > 1:
            with multiprocessing.pool.ThreadPool(processes=number_of_threads) as worker_pool:
                worker_iterator = worker_pool.imap_unordered(self.execute_result, all_filesystem, chunksize=1)
                for feature_scores in worker_iterator:
                    for score in feature_scores:
                        yield score

        else:  # for ordered sequence
            for pe_versions in all_filesystem:
                try:
                    for score in self.execute_result(pe_versions):
                        yield score
                        # Catching group of pes and not per feature because most of the exceptions are because
                        # of Ida and reconnecting will take lots of time.
                except Exception as e:
                    logging.critical(f"Orchestration2 failed {e}", exc_info=True)

    def get_summary(self):
        for iterator in self.iterators:
            if hasattr(iterator, "get_summary"):
                yield iterator, iterator.get_summary()


class OrchestrationSpecificKB(OrchestrationFeatures):
    def __init__(self, iterators, configurations, kb_version,
                 is_include_prev_ver=False, is_include_version_after=False, **kwargs):

        self.is_include_version_after = is_include_version_after
        self.is_include_prev_ver = is_include_prev_ver
        self.kb_ver = self._validate_kb_name(kb_version)
        super().__init__(iterators, configurations, **kwargs)

    def _validate_kb_name(self, kb_name):
        lower = kb_name.lower()
        if not lower.startswith("kb"):
            raise ValueError(f"KB version should be in the following format: KB\d+ but got {kb_name}")

        return lower

    def _reduce_pes(self, all_pes):
        pes = super(OrchestrationSpecificKB, self)._reduce_pes(all_pes)
        pes.sort(key=lambda x: x.version)
        found_index = -1
        for index, pe in enumerate(pes):
            if pe.kb_version == self.kb_ver:
                found_index = index
                break

        if found_index == -1:
            return []

        pes_to_return = [pes[found_index]]
        if self.is_include_prev_ver and found_index > 0:  # it is not the first one
            pes_to_return = [pes[found_index - 1]] + pes_to_return

        if self.is_include_version_after and ((found_index + 1) < len(pes)):  # it is not last
            pes_to_return.append(pes[found_index + 1])

        return pes_to_return


class OrchestrationContinueExecution(OrchestrationFeatures):
    def __init__(self, iterators, configurations, starting_package_name, **kwargs):
        self.starting_package_name = starting_package_name
        self.is_found = False
        super().__init__(iterators, configurations, **kwargs)

    def _reduce_groups(self, reduced_groups):
        if self.is_found:
            return super(OrchestrationContinueExecution, self)._reduce_groups(reduced_groups)
        else:
            return []

    def _reduce_pes(self, pes):
        if len(pes) <= 0:
            return pes

        if self.starting_package_name in pes[0].package_name or self.starting_package_name in pes[0].name:
            self.is_found = True

        if self.is_found:
            return super(OrchestrationContinueExecution, self)._reduce_pes(pes)

        logging.info(f"OrchestrationContinueExecution skipping {pes[0].package_name}")
        return []


class OrchestrationSpecificPEs(OrchestrationFeatures):
    def __init__(self, iterators, configurations, file_names, **kwargs):
        if file_names is not None:
            self.file_names = file_names
        else:
            self.file_names = configurations.configs.orchestration.pe_executable_list

        super().__init__(iterators, configurations, **kwargs)

    def _reduce_pes(self, pes):
        if len(pes) <= 0:
            return pes

        is_found = self.compare_pe_name(pes)

        if is_found:
            return super(OrchestrationSpecificPEs, self)._reduce_pes(pes)

        logging.info(f"OrchestrationSpecificPEs skipping {pes[0].package_name}")
        return []

    def compare_pe_name(self, pes):
        is_found = False
        for file_name in self.file_names:
            if file_name in pes[0].package_name or file_name in pes[0].name:
                is_found = True

        return is_found
