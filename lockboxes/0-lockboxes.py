#!/usr/bin/python3
def canUnlockAll(boxes):
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
