#!/usr/bin/python3
"""log parsing"""

import sys

i = size = 0
dict = {'200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0
}

try:
    for line in sys.stdin:
        try:
            if i != 0 and i % 10 == 0:
                print("File size: {}".format(size))
                for key in sorted(dict.keys()):
                    if dict[key] != 0:
                        print("{}: {}".format(key, dict[key]))
        except:
            pass
        try:
            size += int(line.split()[-1])
        except:
            pass
        i += 1
        try:
            if str(line.split()[7]) in dict.keys():
                dict[str(line.split()[7])] += 1
        except:
            pass
except KeyboardInterrupt:
    print("File size: {}".format(size))
    for key in sorted(dict.keys()):
        if dict[key] != 0:
            print("{}: {}".format(key, dict[key]))
    raise
