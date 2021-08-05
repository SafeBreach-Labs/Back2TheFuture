import time
import github.GithubException
import base64
import enchant
import github
from github import Github
import logging
import re
import sqlite3
import requests.exceptions

import core
import core.utils
import features
import core.function
import core.score
import core.configurations

logging.getLogger("github.Requester").setLevel(logging.WARNING)


class SearchResult(object):
    def __init__(self, **kwargs):
        self.kwargs = kwargs

    def strict_serialize(self):
        return self.kwargs


class GithubScraper(features.feature.SingleTimeFeature):
    METHOD_NAME = "GithubScraper"

    def __init__(self, token=None, path_db_functions=None, table_name=None,
                 is_break_on_first_match=True, minimal_function_len=9, max_rate_limit=5000):
        super().__init__(GithubScraper, type(self).METHOD_NAME)
        github_scraper_configs = core.configurations.get_global().configs.features.global_features.github_scraper
        if path_db_functions is None:
            path_db_functions = github_scraper_configs.msdn_db_location
        if token is None:
            token = github_scraper_configs.token
        if table_name is None:
            table_name = github_scraper_configs.pull_table_name

        self.time_sleep_between_requests = 1 / (max_rate_limit / 60 / 60) + 0.1
        self.max_results_per_search = github_scraper_configs.max_results_per_function
        self.exclude_functions = github_scraper_configs.exclude_functions
        self.table_name = table_name
        self.path_db = path_db_functions
        self.is_break_on_first_match = is_break_on_first_match
        if token is None:
            raise ValueError("token can't be None")
        self.github = Github(token)

        self.minimal_function_len = minimal_function_len
        self.english_words = enchant.Dict("en")  # any type of en

    def explicit_term(self, func_name):
        return f'" {func_name}("'

    def function_name_to_searchable(self, func_name, attributes):
        raw_search = self.explicit_term(func_name)
        encoded_attributes = ""
        for key_attribute, val_attribute in attributes:
            encoded_attributes += f" {key_attribute}:{val_attribute} "
        full_search = f"{raw_search} {encoded_attributes}"
        return full_search

    def get_code_examples(self, search_results, explicit_terms):
        repos_found = []
        searched_pathes = set()
        for index, result in enumerate(search_results):
            time.sleep(self.time_sleep_between_requests)
            if index > self.max_results_per_search:
                logging.debug(f"reached max results {self.max_results_per_search} for {explicit_terms} stopping")
                return repos_found
            # is searched looked for that file already? (forks and so)
            result_id = result.path
            if result_id in searched_pathes:
                continue

            searched_pathes.add(result_id)
            file_content = base64.b64decode(result.content).decode("unicode_escape")
            is_found = True
            for explicit_term in explicit_terms:
                if re.search(explicit_term, file_content) is None:
                    is_found = False
                    break

            if not is_found:
                continue

            search_result = {"path": result.path, "content": file_content,
                             "html_url": result.html_url, "raw_ulr": result.download_url,
                             "owner": result.repository.owner.login, "repo_name": result.repository.name}
            repos_found.append(search_result)
            if self.is_break_on_first_match:
                break

        return repos_found

    def search_in_github(self, function_name, full_func_name):
        attributes = [("language", "C++"), ("language", "C"), ("extension", "c"), ("extension", "cpp"),
                      ("extension", "cc"), ("extension", "cxx")]
        searchable_text = self.function_name_to_searchable(function_name, attributes)
        minimum_results = min(100, self.max_results_per_search * 3)
        search_results = self.github.search_code(searchable_text)
        re_escaped_func_name = re.escape(function_name)
        explicit_terms = [fr"[\s=]{re_escaped_func_name}\("]
        code_examples = self.get_code_examples(search_results, explicit_terms)
        results = []
        for code_example in code_examples:
            results.append(SearchResult(**code_example, function_name=function_name, full_func_name=full_func_name))
        return results

    def is_searable_function_name(self, function_name):
        if len(function_name) < self.minimal_function_len:
            return False

        if function_name in self.exclude_functions:
            return False

        # builtin functions, destructor
        if function_name.startswith("operator") or "~" in function_name:
            return False
        if " " in function_name:
            logging.debug(f"skipping function with space in it's name {function_name}")
            return False

        if self.english_words.check(function_name):  # word exist
            return False
        return True

    def max_searches(self):
        try:
            remaining = self.github.get_rate_limit()
            return remaining.raw_data['core']['remaining']
        except Exception as e:
            logging.warning("get rate limit raised exception")

        return 0

    def _score(self, _):
        logging.info("begin github scraper")
        db_connection = sqlite3.connect(self.path_db)
        cur = db_connection.cursor()
        sql_query = f"select distinct ranked_name from {self.table_name} order by ranked_name"
        results = core.utils.sql_get_results(cur, sql_query, is_include_column_names=False)
        for index, raw_function_name in enumerate(results):
            yield from self.search_function(raw_function_name[0])
        logging.info("finished github scraper")
        db_connection.close()

    def search_function(self, function_name):
        try:
            shorten_func_name = core.function.Function.get_basic_name(function_name)
            is_searchable = self.is_searable_function_name(shorten_func_name)
            if not is_searchable:
                return

            results = self.search_in_github(shorten_func_name, function_name)
            for result in results:
                yield core.score.Result(type(self).METHOD_NAME, [result])

            # to validate we're not reaching rateLimit of 5K requests per second.
            time.sleep(self.time_sleep_between_requests)
        except UnicodeDecodeError:
            logging.debug(f"failed to parse results of page {function_name}")
        except (github.RateLimitExceededException, requests.exceptions.ConnectionError) as e:
            current_max_searches = self.max_searches()
            logging.info(f"got blocked connection due to {e}, in function {function_name} " \
                         f"now have {current_max_searches}")
            time_to_sleep = 9
            if current_max_searches < 100:
                logging.info(f"reached github limit token limit, {current_max_searches}, sleeps for 10 min.")
                time_to_sleep = 10 * 60
            time.sleep(time_to_sleep)

        except requests.exceptions.RequestException as e:
            logging.debug(f"request error in the function {function_name} due to {e}")
        except github.GithubException as e:
            logging.debug(f"github error in the function {function_name} due to {e}")
        except Exception as e:
            logging.debug(f"other exception raised from {function_name} due to {e}")
