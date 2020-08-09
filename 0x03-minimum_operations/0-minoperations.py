#!/usr/bin/python3
"""
this file contains the min operations algorithm
"""

def _isprime(n):
    if n > 1:
        for i in range(2,n):
            if (n % i) == 0:
                return False
        return True
    else:
        return False

def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            factors.append(n // i)
            n //= i
    if n > 1:
        factors.append(n // i)
    return sorted(factors)


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
        div_li = prime_factors(n)
        i = 0
        ops_li.append('cp_all')
        while (lenchar != n):
            ops_li.append('paste')
            lenchar += div_li[i]
            if i < len(div_li) - 1 and lenchar == div_li[i + 1] and lenchar < n:
                i += 1
                ops_li.append('cp_all')
    return len(ops_li)
