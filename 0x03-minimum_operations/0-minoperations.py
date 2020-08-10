#!/usr/bin/python3
"""
this file contains the min operations algorithm
"""


def minOperations(n):
    """calculates the fewest number of operations
    needed to result in exactly n H characters """
    if type(n) != int or n <= 1:
        return 0

    nops = 0
    i = 2
    while i <= n:
        if n % i == 0:
            n //= i
            nops += i
        else:
            i += 1
    return nops
