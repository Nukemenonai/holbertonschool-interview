#!/usr/bin/python3
"""
this file contains the min operations algorithm
"""


def _isprime(n):
    """ checks for primality of n"""
    if n < 2:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
        else:
            return True


def find_ld(n):
    """finds the largest divisor of n and the largest of each subsequent"""
    div_li = []
    while n > 1:
        for i in range(2, n):
            if n % i == 0:
                div_li.append(n / i)
                n = int(n / i)
    return sorted(div_li)


def minOperations(n):
    """calculates the fewest number of operations
    needed to result in exactly n H characters """
    if type(n) != int or n <= 1:
        return 0
    if _isprime(n) is True:
        return n
    else:
        lenchar = 1
        ops_li = []
        div_li = find_ld(n)
        i = 0
        ops_li.append('cp_all')
        while (lenchar != n):
            ops_li.append('paste')
            lenchar += div_li[i]
            if i < len(div_li) - 1 and lenchar == div_li[i + 1] and lenchar < n:
                i += 1
                ops_li.append('cp_all')
    return len(ops_li)
