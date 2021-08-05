import re
import csv
import logging
import os
import sqlite3

import core.configurations
import core.score
import core.utils
import features.feature
import features.groupby


def get_cve_to_pe_db_location():
    configurations = core.configurations.get_global()
    db_location = configurations.configs.features.pe.cve_link.db_location
    if not os.path.exists(db_location):
        raise FileNotFoundError("Could not find the DB cve to PE correlation "
                                "please validate that in the configurations and in the filesystem. ")
    return db_location


def get_cve_to_exploit_db():
    configurations = core.configurations.get_global()
    db_location = configurations.configs.features.pe.cve_link.cve_to_exploit_db
    if not os.path.exists(db_location):
        raise FileNotFoundError("Could not find the DB cve to exploit, please validate that in the configurations. ")
    return db_location


def get_cve_records(sql, db_location=None):
    if db_location is None:
        db_location = get_cve_to_pe_db_location()

    if not os.path.exists(db_location):
        raise FileNotFoundError(f"could not find DB {db_location}")

    conn = sqlite3.connect(db_location)
    cur = conn.cursor()
    yield from core.utils.sql_get_results(cur, sql)

    conn.close()


def get_all_records_related_to_pe(pe_obj):
    if pe_obj.kb_version is not None:
        kb_version = pe_obj.kb_version[2:]  # without kb prefix
        sql = f"SELECT * FROM cve_patch_files WHERE file_name == '{pe_obj.name}' AND kb_name == '{kb_version}'"
    else:
        raise NotImplementedError("not planned to be implemented")

    for result in get_cve_records(sql):
        yield result


class LinkCVEToUpdate(features.feature.PEFeature):
    METHOD_NAME = "LinkCVEToUpdate"

    def __init__(self, path_manual_csv_exploits=None, cve_to_pe_db_location=None, cve_to_exploit_db=None):
        self.cve_to_exploit_db = cve_to_exploit_db
        self.db_location = cve_to_pe_db_location
        if path_manual_csv_exploits is None:
            path_manual_csv_exploits = core.configurations.get_global().configs.features.pe.cve_link.path_manual_csv_exploits

        self.manual_cves = type(self)._parse_csv(path_manual_csv_exploits)

        compared_number = 2
        path_cve_to_pe = get_cve_to_pe_db_location()
        path_exploit_db = get_cve_to_exploit_db()
        if not os.path.exists(path_exploit_db) or not os.path.exists(path_cve_to_pe):
            logging.error(f"Path to exploit DB '{path_exploit_db}' or path to cve correlation could not be found '{path_cve_to_pe}'\n"
                          f"validate that in the config file and in the filesystem.")
            raise
        group_by = features.groupby.GroupByOrderedPE(compared_number)
        super().__init__(type(self).METHOD_NAME, compared_number, group_by)

    @staticmethod
    def validate_csv_args(cve_id, url):
        if not url.startswith("http"):
            return False
        if re.match("CVE-\d+-\d+", cve_id):
            return True

        return False


    @staticmethod
    def _parse_csv(path_csv):
        results = {}
        with open(path_csv, "r") as csvfile:
            cve_reader = csv.reader(csvfile, delimiter=',')
            next(cve_reader, None)  # skip header
            for cve_id, url in cve_reader:
                upper_cve_id = cve_id.upper()
                url = url.strip()
                if url.startswith('"'):
                    url = url[1:-1]

                if LinkCVEToUpdate.validate_csv_args(upper_cve_id, url):
                    results.update({upper_cve_id: url})
                else:
                    logging.warning(f"skipping csv row because the row contains not valid info {upper_cve_id} {url}")

        return results

    def _score(self, compare_object):
        import compare.compare
        changed = len(list(compare_object.get_changes(compare.compare.TypesOfChanges.CHANGED)))
        added = len(list(compare_object.get_changes(compare.compare.TypesOfChanges.ADDED)))
        removed = len(list(compare_object.get_changes(compare.compare.TypesOfChanges.REMOVED)))
        total_sum = changed + added + removed
        if total_sum <= 0:
            is_debug = core.configurations.get_global().configs.is_debug
            if is_debug:
                pe_obj = compare_object.objects_to_compare[compare.compare.NEWEST]
                records_related_to_pe = get_all_records_related_to_pe(pe_obj)
                if len(list(records_related_to_pe)) > 0:
                    logging.debug(f"LinkCVEToUpdate ignoring because there was no change {compare_object.objects_to_compare}")

            return  # instead of raise stopIteration

        pe_obj = compare_object.objects_to_compare[compare.compare.NEWEST]
        records_related_to_pe = get_all_records_related_to_pe(pe_obj)
        for record in records_related_to_pe:
            if record['match_score'] <= 0:
                logging.debug(f"LinkCVEToUpdate ignoring because of negative score {compare_object.objects_to_compare}")
                continue

            optional_arguments = {}
            if 'CWE_name' in record and record['CWE_name'] is not None:
                optional_arguments.update({"CWE_name": record['CWE_name']})

            if 'cve_name' in record and record['cve_name'] is not None:
                optional_arguments.update({"cve_name": record['cve_name']})
                exploits = self._find_exploit_details(record['cve_name'])
                optional_arguments.update(exploits)

            if 'vulType' in record and record['vulType'] is not None:
                optional_arguments.update({"vulnerability_type": record['vulType']})

            cwe_id = record.get('CWE_id', None)
            # scores must be below 100.
            normalize_score = 10 + record['match_score'] / 100
            yield core.score.Score(normalize_score, type(self), [pe_obj], relevant_cwes=[cwe_id],
                                   **optional_arguments)

    def _find_exploit_details(self, cve_id):
        """

        :param cve_id: str in format CVE-XXXX-XXXXXX
        :return: dict with key resource of the exploit (such as github, exploitDB) and the value is url
        """
        location = get_cve_to_exploit_db()
        websites_for_exploits = dict(exploit_github=list(self._github_exploits_urls(cve_id, location)),
                                     exploit_exploitdb=list(self._exploit_db_urls(cve_id, location)),
                                     exploit_manual=list(self._manual_link_cve(cve_id)))
        all_exploits = {}
        for website, uris in websites_for_exploits.items():
            for index, uri in enumerate(uris):
                all_exploits.update({f"{website}_{index}": uri})

        return all_exploits

    def _exploit_db_urls(self, cve_id, db_location):
        sql = f"select edb_id from exploitdb where cve_id like '{cve_id}'"
        exploit_db_base_url = core.configurations.get_global().configs.features.pe.cve_link.exploit_db_base_url
        records = get_cve_records(sql, db_location)
        for record in records:
            full_edb_url = exploit_db_base_url.format(record['edb_id'])
            yield full_edb_url

    def _github_exploits_urls(self, cve_id, db_location):
        sql = f"select label from github where cve_id like '{cve_id}'"
        records = get_cve_records(sql, db_location)
        for record in records:
            yield record['label']

    def _seebug_exploits_urls(self, cve_id, db_location):
        sql = f"select ssv from seebug where cid like '{cve_id}'"
        records = get_cve_records(sql, db_location)
        for record in records:
            raise NotImplementedError("yet, I don't know how to convert SSV to URL")
            yield record['ssv'] #

    def _manual_link_cve(self, cve_id):
        upper_case = cve_id.upper()
        if upper_case not in self.manual_cves:
            return

        yield self.manual_cves[upper_case]
