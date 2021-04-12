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

    if len(walls) == 0:
        return 0

    total = 0

    for i in range(len(walls)):
        if i == 0 or i == (len(walls)):
            continue
        if walls[i - 1] > walls[i] and walls[i + 1] > walls[i]:
            # este es un hueco
            total += min(walls[i - 1], walls[i + 1])

    return total
