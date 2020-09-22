#!/usr/bin/python3
"""
utf validator
"""


def validUTF8(data):
    """
    checks if an array if integers representing a UTF-8 is valid UTF-8
    data: list of integers
    returns: true if valid else 0
    """
    binary = []
    for number in data:
        if type(number) != int:
            return False
        binary.append("{:08b}".format(number))
    for byte in binary:
        if int(byte[0]) == 0:
            continue
        ones = byte.count('1')
        if ones >= 4 or ones <= 1:
            return False
        for _ in range(ones - 1):
            try:
                byte = next(binary)
            except StopIteration:
                return False
            if byte[:2] != ['10']:
                return False
    return True
