#!/usr/bin/python3
""" this file contains the canunlock all main function
and its subordinate recursive function"""


def canUnlockAll(boxes):
    """ returns true if all boxes can be unlocked else false"""
    boxescp = boxes
    foundkeys = []
    unlockRecursively(boxescp, 0, foundkeys)
    for llave in foundkeys:
        unlockRecursively(boxescp, llave, foundkeys)
    for box in boxescp:
        if 'open' not in box:
            return False
    return True


def unlockRecursively(boxescp, idx, foundkeys):
    """ recursive algorithm that unlocks all available boxes"""
    for llave in boxescp[idx]:
        if llave not in foundkeys:
            foundkeys.append(llave)
        boxescp[idx].remove(llave)
    boxescp[idx].append('open')
