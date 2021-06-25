#!/usr/bin/python3
"""
Making change 
"""

def makeChange(coins, total):
    """ Given a pile of coins of different values,
    determine the fewest number of coins
    needed to meet a given amount total

    Args:
        coins: list of the values of the coins in your possession
        total: total to be met
    """
    sum = 0
    i = 0
    count = 0

    if total <= 0:
        return 0

    sorted_coins = sorted(coins, reverse=True)
    n_denom = len(sorted_coins)
    aux = total - sum

    while sum < total and i < n_denom:
        while s_coins[i] <= aux:
            sum += sorted_coins[i]
            count += 1
            if sum == total:
                return count
            aux = total - sum
        i += 1

    return -1