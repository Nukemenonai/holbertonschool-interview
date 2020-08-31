#!/usr/bin/python3
"""log parsing"""

import sys


def print_log(size, dictionary):
    """Prints the summary of the log parsing"""
    print("File size: {}".format(size))
    for key in sorted(dict.keys()):
        if dict[key] != 0:
            print("{}: {}".format(key, dict[key]))

i = 0
size = 0
dict = {'200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0}

try:
    for line in sys.stdin:
        if i != 0 and i % 10 == 0:
            print_log(size, dict)
        i += 1
        size += int(line.split()[-1])

        if str(line.split()[-2]) in dict.keys():
            dict[str(line.split()[-2])] += 1
    print_log(size, dict)

except KeyboardInterrupt:
    print_log(size, dict)
    raise
