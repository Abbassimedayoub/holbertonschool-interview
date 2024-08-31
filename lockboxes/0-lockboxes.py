#!/usr/bin/python3
""" Function that solve the locked boxes problem"""


def canUnlockAll(boxes):
    """
    Return if all boxex can be unlocked
    :parm boxes : list of list wehere each list
    represent the compoment of a box
    :return: True if all boxes can be opened
    and false otherwise
    """
    n = len(boxes)
    unloked = [False] * n  # initialise that all boxes are loked
    unloked[0] = True  # the first box is usally unloked
    keys = set(boxes[0])  # create a set where we will stock all the keys
    while keys:
        new_keys = set()
        for key in keys:
            if key < n and not unloked[key]:
                unloked[key] = True
                new_keys.update(boxes[key])
        keys = new_keys
    return all(unloked)
