#!/usr/bin/python3
""" this file contains the canunlock all main function
and its subordinate recursive function"""


def canUnlockAll(boxes):
    """ returns true if all boxes can be unlocked else false"""
    foundkeys = []
    unlockRecursively(boxes, 0, foundkeys)
    for llave in foundkeys:
        unlockRecursively(boxes, llave, foundkeys)
    for box in boxes:
        if 'open' not in box:
            return False
    return True


def unlockRecursively(boxes, idx, foundkeys):
    """ recursive algorithm that unlocks all available boxes"""
    for llave in boxes[idx]:
        if llave not in foundkeys:
            foundkeys.append(llave)
        boxes[idx].remove(llave)
    boxes[idx].append('open')
