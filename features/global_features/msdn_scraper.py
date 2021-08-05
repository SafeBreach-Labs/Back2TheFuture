import datetime
import enum
import multiprocessing.pool
import threading
import time
import traceback
import abc
from urllib.parse import urljoin
import pprint
import json
from bs4 import BeautifulSoup
import requests
import logging
import os
import sys
import re

import core.score
import features.feature
import core.score

if __name__ == "__main__":
    cwd = os.path.dirname(os.path.dirname(os.path.dirname(__file__)))
    sys.path.append(cwd)
    ROOT_DIR = os.path.dirname(os.path.dirname(os.path.dirname(__file__)))
    full_log_file = os.path.join(ROOT_DIR, "logs", 'msdn_scraper.log')
    logging.basicConfig(filename=full_log_file, level=logging.DEBUG,
                        datefmt='%Y-%m-%d %H:%M:%S', format='%(name)s %(asctime)s - %(levelname)s - %(message)s')
    stdout_formatter = logging.Formatter('%(levelname)s - %(message)s')
    stream_handler = logging.StreamHandler(sys.stdout)
    stream_handler.setFormatter(stdout_formatter)
    logging.getLogger().addHandler(stream_handler)

logging.getLogger("urllib3").setLevel(logging.WARNING)
logging.getLogger("requests").setLevel(logging.WARNING)

SELENIUM_WEB_DRIVER = None
SELENIUM_WEB_DRIVER_LOCK = threading.Lock()
IS_RUN_HEADLESS = True  # to hide firefox GUI


class FunctionDeclaration(object):
    def __init__(self, raw_declaration):
        self.raw_declaration = raw_declaration

    def get_return_value_type(self):
        return self.raw_declaration.split(" ")[0]  # TODO: add support with CPP.

    def get_arguments(self):  # each var has unique line
        one_line_dec = self.raw_declaration.replace("\n", "")
        match_args = re.match(r".*?\((.*)\).*?", one_line_dec)  # keep (.*) and not (.+) to support no arguments.
        if match_args is None:
            logging.error(f"error parsing variable {one_line_dec}")
            raise ValueError(f"failed to parse signature {one_line_dec}")

        arguments = match_args.group(1).split(",")
        if len(arguments) == 1 and len(arguments[0]) == 0:  # there are no arguments
            return []

        ret_val = []
        for arg in arguments:
            pattern_match = re.match(r"\W+(\w+)\W+(\w+),?", arg)  # we might want to replace it with \s
            if pattern_match is None:
                logging.error(f"error parsing variable {arg}")
                raise ValueError(f"failed to parse arg {arg}")

            param_type = pattern_match.group(1)
            param_name = pattern_match.group(2)
            ret_val.append((param_type, param_name))

        return ret_val

    def __str__(self):
        return str(self.raw_declaration)

    def __repr__(self):
        return str(self)


class ParamterInputOrOutput(enum.Enum):
    IN = 0
    OUT = 1
    IN_OUT = 3
    RETURN_VALUE = 4


class Requirement(object):
    def __init__(self):
        super().__init__()

    def __str__(self):
        return str(vars(self))

    def __repr__(self):
        return str(self)


class HeaderRequirement(Requirement):
    def __init__(self, ):
        super().__init__()

    def __str__(self):
        return str(vars(self))

    def __repr__(self):
        return str(self)


class Parameter(object):
    def __init__(self, name, param_type, optional_values=None, argument_direction=None, description=None):
        """
        name: name of the parameter
        parameter_type: type, such as int, bool... 
        optional_values: if known values(flags and so)
        arguemnt_direction = choose value from the enum ParamterInputOrOutput
        """
        self.name = name
        self.param_type = param_type
        self.optional_values = optional_values
        self.argument_direction = argument_direction
        super().__init__()

    def strict_serialize(self):
        return {"name": self.name, }

    def __str__(self):
        return str(vars(self))

    def __repr__(self):
        return str(self)


class WebPage(object):
    def __init__(self, url, raw_webpage, alerts=None, notes=None):
        self.notes = notes
        self.raw_webpage = raw_webpage
        self.url = url
        self.alerts = alerts
        super().__init__()

    def strict_serialize(self):
        return {"url": self.url,
                "raw_webpage": self.raw_webpage,
                "alerts": self.alerts,
                "notes": self.notes
                }

    def __str__(self):
        return str(vars(self))

    def __repr__(self):
        return str(self)


class FunctionWebPage(WebPage):
    def __init__(self, header, description, signature, parameters, return_value, requirements, url,
                 examples_usage=None, raw_webpage=None, alerts=None, notes=None):
        self.header = header
        self.description = description
        self.signature = signature
        self.parameters = parameters
        self.requirements = requirements
        self.return_value = return_value
        if examples_usage is None:
            self.usage_examples = []
        else:
            self.usage_examples = examples_usage

        super().__init__(url, raw_webpage, alerts, notes)

    def get_name(self):
        return self.header.split(" ")[0]

    def strict_serialize(self):
        serialized_params = []
        for param in self.parameters:
            serialized_params.append(param.strict_serialize())
        args = {}
        args.update(super().strict_serialize())
        args.update({"name": self.get_name(),
                     "signature": str(self.signature),
                     "ret_val_type": self.signature.get_return_value_type(),
                     "description": self.description,
                     "params": serialized_params,
                     "code_examples": self.usage_examples})
        return args

    def __repr__(self):
        return str(self)

    def __str__(self):
        return str(vars(self))


class StructWebPage(WebPage):
    def __init__(self, header, description, signature, arguments, url, raw_webpage):
        self.header = header
        self.description = description
        self.signature = signature
        self.arguments = arguments
        super().__init__(url, raw_webpage)

    def get_name(self):
        return self.header.split(" ")[0]

    def strict_serialize(self):
        serialized_arguments = []
        for argument in self.arguments:
            serialized_arguments.append(argument.strict_serialize())
        args = {}
        args.update(super().strict_serialize())
        args.update({"name": self.get_name(),
                     "signature": str(self.signature),
                     "description": self.description,
                     "params": serialized_arguments
                     })
        return args

    def __str__(self):
        return str(vars(self))

    def __repr__(self):
        return str(self)


class ParseWebPage(abc.ABC):
    def parse(self, parsed_webpage, url):
        raise NotImplementedError("not implemented")

    def parse_entire_html(self, parsed_webpage):
        return str(parsed_webpage)

    def parse_header(self, parsed_webpage):
        raw_header = find_only_one(parsed_webpage, "h1")
        header = raw_header.text
        return header

    def parse_alerts(self, parsed_webpage):
        all_results = parsed_webpage.find_all("div", class_="alert is-primary")
        alerts = []
        for alert in all_results:
            alerts.append(alert.text)
        return alerts

    def parse_notes(self, parsed_webpage):
        all_results = parsed_webpage.find_all("div", class_="alert")
        alerts = []
        for alert in all_results:
            alerts.append(alert.text)
        return alerts

    def parse_description(self, parsed_webpage):
        pre_description = find_only_one(parsed_webpage, id="center-doc-outline")
        raw_description = pre_description.findNextSibling()
        description = ""

        # for warnings such as https://docs.microsoft.com/en-us/windows/win32/api/msdrmdefs/nc-msdrmdefs-drmcallback
        # or https://docs.microsoft.com/en-us/windows/win32/api/strmif/nf-strmif-ifiltermapper-registerfilterinstance
        class_attr = raw_description.attrs.get("class", [None])
        if raw_description.name == "div" and class_attr[0] in ["NOTE", "alert", "alert is-primary", "IMPORTANT"]:
            description += raw_description.text + "\n\n\n\n"
            raw_description = raw_description.findNextSibling()
            # https://docs.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-cryptdecrypt
            cur_iterator = raw_description.next.next
            if cur_iterator.name == None:
                logging.warning("description format contains text without p mark, might missing some description")
                raw_description = cur_iterator.find_next("p")

            # to support https://docs.microsoft.com/en-us/windows/win32/api/uiautomationcoreapi/nf-uiautomationcoreapi-virtualizeditempattern_realize 
            if raw_description.name == "div" and len(raw_description.text) < 10:
                raw_description = raw_description.findNextSibling()

        # no description  https://docs.microsoft.com/en-us/windows/win32/api/mileffects/nf-mileffects-imilbitmapeffectoutputconnectorimpl-addbacklink
        if raw_description.name == "h2":
            return description

        if raw_description.name != "p":
            raise ValueError(f"expected p and not {raw_description.name}")
        else:
            description += raw_description.text

        return description

    def parse_element_signature(self, parsed_webpage):
        # TODO: add support with https://docs.microsoft.com/en-us/windows/win32/api/directml/ns-directml-dml_element_wise_recip_operator_desc
        # it really rare.
        raw_func_signature = parsed_webpage.find(
            attrs={"lang-cpp"})  # find only the first one, the second is the code example.
        func_signature = raw_func_signature.text
        return FunctionDeclaration(func_signature)

    def parse_parameter_block(self, first_id):
        params = []
        next_param = first_id
        while next_param.name == "p" and next_param.next.name == "code":  # for multi paragraphs docs.
            param_name = next_param.text
            raw_param_description = next_param.findNextSibling()
            if raw_param_description.name != "p":
                if len(params) == 0:  # it means that this function doesn't get any paramters
                    return []
                else:
                    # parameter doesn't have description, only name 
                    # https://docs.microsoft.com/en-us/windows/win32/api/certadm/nf-certadm-iocspadmin-getsigningcertificates
                    params.append((param_name, None))
                    next_param = raw_param_description.findNextSibling()
                    continue
            param_description = raw_param_description.text
            next_param = raw_param_description.findNextSibling()  # go to the next param.
            if next_param is None:  # reached end of the page.
                break
            while next_param.name == "p" and next_param.next.name != "code":  # get the next paragraphs
                param_description += "\n\n" + next_param.text
                next_param = next_param.findNextSibling()  # go to the next param.
                if next_param is None:  # reached end of the page.
                    break

            params.append((param_name, param_description))

        return params

    def parse_usage_example(self, parsed_webpage):
        code_headers = parsed_webpage.find_all("code", {"class": lambda x: x is not None and x.startswith("lang-")})
        raw_func_signatures = code_headers
        if len(raw_func_signatures) < 2:
            return None  # there is no example
        elif len(raw_func_signatures) > 2:
            logging.debug(f"have more than 2 code sections, taking the last one")

        examples = []
        for i in raw_func_signatures[1:]:
            examples.append((i.text, i.attrs['class'][0]))
        return examples

    def __str__(self):
        return str(vars(self))

    def __repr__(self):
        return str(self)


class ParseStruct(ParseWebPage):
    def parse(self, parsed_webpage, url):
        header = self.parse_header(parsed_webpage)
        description = self.parse_description(parsed_webpage)
        struct_signature = self.parse_element_signature(parsed_webpage)
        raw_webpage = self.parse_entire_html(parsed_webpage)
        return StructWebPage(header, description, struct_signature, [], url, raw_webpage)

    def _parse_parameters(self, parsed_webpage, function_signature):
        header_parameters = parsed_webpage.find(id="members")
        if header_parameters is None:
            raise ValueError("doesn't have parameter")

        next_param = header_parameters.findNextSibling()
        params = self.parse_parameter_block(next_param)
        return params


class ParseFunction(ParseWebPage):
    def parse(self, parsed_webpage, url):
        header = self.parse_header(parsed_webpage)
        description = self.parse_description(parsed_webpage)
        func_signature = self.parse_element_signature(parsed_webpage)
        parameters = self._parse_parameters(parsed_webpage, func_signature)
        ret_val = self._parse_return_val(parsed_webpage, func_signature)
        requirements = parse_requirements(parsed_webpage)
        examples_usage = self.parse_usage_example(parsed_webpage)
        raw_webpage = self.parse_entire_html(parsed_webpage)
        alerts = self.parse_alerts(parsed_webpage)
        notes = self.parse_notes(parsed_webpage)
        webpage = FunctionWebPage(header, description, func_signature, parameters, ret_val, requirements, url,
                                  examples_usage=examples_usage, raw_webpage=raw_webpage, alerts=alerts,
                                  notes=notes)
        return webpage

    def _parse_parameters(self, parsed_webpage, function_signature):
        header_parameters = parsed_webpage.find(id="parameters")
        if header_parameters is None:
            raise ValueError("doesn't have parameter")

        next_param = header_parameters.findNextSibling()
        raw_params = self.parse_parameter_block(next_param)
        index = 0
        params = []
        # func_arguments = function_signature.get_arguments() # TODO: return that.
        for param_name, description in raw_params:
            # param = Parameter(param_name, func_arguments[index][0],description=description) # also this one.
            param = Parameter(param_name, "paramter_type_place_holder", description=description)
            params.append(param)
            index += 1
        return params

    def _parse_return_val(self, parsed_webpage, function_signature):
        title_return_val = parsed_webpage.find(id="return-value")
        if title_return_val is None:
            raise ValueError(
                "_parse_return value could not find return value title")  # TODO: what happend on void functions?

        sib = title_return_val.findNextSibling()
        text = sib.text
        if sib.name != "p":
            logging.warning("_parse_return value find different value")
            text = None

        return Parameter(None, function_signature.get_return_value_type(), None, ParamterInputOrOutput.RETURN_VALUE,
                         description=text)


def find_only_one(parsed_webpage, *args, **kwargs):
    results = parsed_webpage.find_all(*args, **kwargs)
    if len(results) != 1:
        # not supporting this bug https://docs.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_all_option_values
        raise ValueError(f"Expected list len 1 but got {len(results)}")

    return results[0]


def get_webpage(page_url):
    with SELENIUM_WEB_DRIVER_LOCK:
        global SELENIUM_WEB_DRIVER
        if SELENIUM_WEB_DRIVER is None:
            try:
                import selenium.webdriver
                import webdriver_manager.firefox
                from selenium.webdriver.firefox.options import Options
                options = Options()
                options.headless = IS_RUN_HEADLESS
                profile = selenium.webdriver.FirefoxProfile()
                profile.set_preference("browser.tabs.warnOnClose", False)
                geko_driver = webdriver_manager.firefox.GeckoDriverManager()
                driver = selenium.webdriver.Firefox(options=options, firefox_profile=profile,
                                                    executable_path=geko_driver.install())
                SELENIUM_WEB_DRIVER = driver
            except Exception:
                logging.critical("failed to get and install the firefox driver")
                raise
        SELENIUM_WEB_DRIVER.get(page_url)
        return SELENIUM_WEB_DRIVER.find_element_by_tag_name('HTML').get_attribute('innerHTML')


def extract_function_info_from_page(page_url):
    try:
        req = requests.get(page_url)
        html_webpage = req.text
        # html_webpage = get_webpage(page_url)
        parsed = BeautifulSoup(html_webpage, "html.parser")
        type_of_page = detect_type_of_website(parsed)
        extracted_website = type_of_page(parsed, page_url)
        return extracted_website
    except Exception as e:
        e.args = list(e.args) + [page_url]
        return e


def detect_type_of_website(parsed):
    raw_header = find_only_one(parsed, "h1")
    header = raw_header.text
    if " method" in header:
        return ParseFunction().parse
    elif " function" in header:
        return ParseFunction().parse
    elif " struct" in header:
        return ParseStruct().parse
    elif " header" in header:
        raise NotImplementedError(f"{header}")
    elif " interface" in header:
        raise NotImplementedError(f"{header}")
    elif " enumeration " in header:
        raise NotImplementedError(f"{header}")
    elif " macro " in header:
        raise NotImplementedError(f"{header}")
    elif " enumeration " in header:
        raise NotImplementedError(f"{header}")
    elif " union " in header:
        raise NotImplementedError(f"{header}")
    elif " IOCTL " in header:
        raise NotImplementedError(f"{header}")
    else:
        raise NotImplementedError(f"{header}")


def parse_requirements(parsed_webpage):
    return []


def scrape_urls(urls, workers=20):
    worker_pool = multiprocessing.pool.ThreadPool(processes=workers)
    for result in worker_pool.imap_unordered(extract_function_info_from_page, urls):
        if isinstance(result, Exception):
            if isinstance(result, NotImplementedError):
                logging.info(f"skipping {result.args} not implemented")
            else:
                logging.warning(f"failed to parse {result.args} {result}")

        else:
            yield result


def get_childrens(base_url, properties):
    full_urls = []
    leaf = properties.get("href", None)
    if leaf is not None:
        yield properties['href']
        # full_urls.append(properties['href'])

    child_properties = properties.get('children', [])
    for child in child_properties:
        name_property = child['toc_title']
        full_urls += get_childrens(base_url, child)

    for i in full_urls:
        yield i


def remove_duplicates_language(urls):
    new_urls = set()
    for url in urls:
        new_url = url.replace("/en-us/", "/")
        new_urls.add(new_url)

    return new_urls


def main(max_pages, workers=20):
    start_orchestration = time.time()
    print('Timestamp: {:%Y-%m-%d %H:%M:%S}'.format(datetime.datetime.now()))
    base_url = "https://docs.microsoft.com/en-us/windows/win32/api"
    url = f"{base_url}/toc.json"
    req = requests.get(url)
    j = json.loads(req.text)
    all_headers = []
    for headers in j['items'][0]['children']:
        all_headers += headers['children']

    groups_full_url = {}
    for header in all_headers:
        header_file_name = header['toc_title']
        groups_full_url[header_file_name] = base_url + "/" + header['href']

    urls_all_pages = set()
    for context_group, file_url in groups_full_url.items():
        full_url = file_url + "/toc.json"
        raw_header_properties_req = requests.get(full_url)
        header_properties_req = json.loads(raw_header_properties_req.text)
        file_properties = header_properties_req['items'][0]
        all_childrens = get_childrens(full_url, file_properties)
        for child in all_childrens:
            if "./" == child:
                continue

            page_url = urljoin(file_url, child)  # this one resolve ../ issue.
            urls_all_pages.add(page_url)

        if len(urls_all_pages) is not None and max_pages is not None and len(urls_all_pages) > max_pages:
            logging.error("reached maximum pages")
            break
    unique_urls = remove_duplicates_language(urls_all_pages)
    logging.info("finished scraping for urls, starting parse pages")
    yield from scrape_urls(unique_urls, workers)
    print("finished pulling")
    print('Timestamp: {:%Y-%m-%d %H:%M:%S}'.format(datetime.datetime.now()))
    end_orchestration = time.time()
    diff_time = end_orchestration - start_orchestration
    delta_time = datetime.timedelta(seconds=diff_time)
    logging.info(f"time diff seconds: {diff_time}, human readable {delta_time}")
    print(f"time diff seconds: {diff_time}, human readable {delta_time}")
    if SELENIUM_WEB_DRIVER is not None:
        SELENIUM_WEB_DRIVER.quit()  # close firefox


class MSDNScraper(features.feature.SingleTimeFeature):
    METHOD_NAME = "MSDNScraper"

    def __init__(self, max_pages=None):
        super().__init__(FunctionWebPage, type(self).METHOD_NAME)
        self.max_pages = max_pages

    def _score(self, _):
        logging.info("begin msdn scraper")
        results = main(self.max_pages)
        for result in results:
            yield core.score.Result(type(self).METHOD_NAME, [result])

        logging.info("finished msdn scraper")


if __name__ == "__main__":
    logging.info("begin scraper")
    t = [ "https://docs.microsoft.com/en-us/windows/win32/api/prntvpt/nf-prntvpt-ptgetprintcapabilities"
        # "https://docs.microsoft.com/windows/win32/api/srpapi/nf-srpapi-srpclosethreadnetworkcontext",
         # "https://docs.microsoft.com/en-us/windows/win32/api/dsclient/nc-dsclient-lpdsenumattributes",
         # "https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strcpy-wcscpy-mbscpy?view=msvc-160"
        ]
    out = scrape_urls(t)
    print(list(out))
    for i in main(100):
        logging.info(i)

    logging.info("end scraper")
