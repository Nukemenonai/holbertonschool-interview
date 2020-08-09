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


def ops_registry(li, n, lenchar, last_batch_copied):
    """ dynamic programming algo"""
    if lenchar >= n:
        return
    if lenchar <= int(n / 2):
        li.append('cpa')
        li.append('pt')
        last_batch_copied = lenchar
        lenchar += last_batch_copied
        ops_registry(li, n, lenchar, last_batch_copied)
    else:
        li.append('pt')
        lenchar += last_batch_copied
        ops_registry(li, n, lenchar, last_batch_copied)


def minOperations(n):
    """calculates the fewest number of operations
    needed to result in exactly n H characters """
    if type(n) != int or n <= 1:
        return 0
    if _isprime(n) is True:
        return n
    else:
        li = []
        ops_registry(li, n, 1, 0)
        return len(li)
