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
    if total <= 0:
        return 0

    sorted_coins = sorted(coins, reverse=True)
    amt = 0

    for coin in sorted_coins:
        if total <= 0:
            break
        aux = total // coin
        amt += aux
        total -= (aux * coin)

    if total != 0:
        return -1

    return amt
