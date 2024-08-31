# Lockbox Problem

## Introduction

The Lockbox problem is a computational challenge where you need to determine if all the boxes in a collection can be unlocked using the keys found within other boxes. This problem can be seen as a graph traversal where each box is a node, and each key represents a directed edge that allows access from one node (box) to another.

## Problem Statement

You are given `n` locked boxes, each numbered sequentially from `0` to `n-1`. Each box may contain one or more keys. A key can be used to unlock the box with the corresponding number. The first box, `boxes[0]`, is unlocked by default. The task is to determine whether it is possible to unlock all the boxes.

## Function Prototype

```python
def canUnlockAll(boxes)
 ```
 
### Parameters
- boxes : 
A list of lists. Each inner list contains integers representing the keys found in that box.
### Returns 
- True if all the boxes can be unlocked.
- False if some boxes remain locked.