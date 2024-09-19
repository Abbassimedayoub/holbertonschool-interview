# Minimum Operations Problem

## Problem Description

Given a number `n`, you can perform two operations:
1. If `n` is divisible by 2, then divide `n` by 2.
2. Otherwise, decrement `n` by 1.

Your goal is to find the minimum number of operations needed to reduce `n` to 0.

## Approach

We use an iterative approach to reduce `n` until it becomes 0:
- Start with `count = 0`.
- While `n` is greater than 0:
  - If `n` is even (`n % 2 == 0`), divide `n` by 2.
  - Otherwise, decrement `n` by 1.
  - Increment `count` after each operation.

## Algorithm

```python
def minOperations(n):
    count = 0
    while n > 0:
        if n is even:
            n = n / 2
        else:
            n = n - 1
        count = count + 1
    return count
