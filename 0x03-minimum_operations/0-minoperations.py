#!/usr/bin/python3
"""
this file contains the min operations algorithm
"""


def ops_registry(li, n, lenchar, last_batch_copied):
    """ dynamic programming algo"""
    if lenchar == n:
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
    li = []
    if n <= 1:
        return 0
    ops_registry(li, n, 1, 0)
    return len(li)
