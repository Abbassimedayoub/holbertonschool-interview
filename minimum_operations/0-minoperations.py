#!/usr/bin/python3
def minOperations(n):
    """
    Return the min number of operation
    :parm n : the number
    :return: the min number of operation
    and 0 if n impossible
    """
    if n <= 1:
        return 0
    num_operation = 0
    factor = 2
    while n > 1:
        while n % factor == 0:
            num_operation += factor
            n //= factor
        factor += 1
    return num_operation
