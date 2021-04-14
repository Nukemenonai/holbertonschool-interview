#!/usr/bin/python3
"""
0_rain
"""


def rain(walls):
    """
    Given a list of non-negative integers representing
    walls of width 1, calculate how much
    water will be retained after it rains.
    """
    total = 0
    n = len(walls)

    if n == 0:
        return 0

    total = 0

    for i in range(1,  n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]

        for j in range(i + 1, n):
            right = max(right, walls[j])

        total += (min(left, right) - walls[i])

    return total
