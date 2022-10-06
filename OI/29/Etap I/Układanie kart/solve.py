#!/bin/python

import math

def f(n: int) -> int:
    if n == 3:
        return 1
    else:
        return f(n - 1) * (n - 1) + 1

def add(n: int) -> int:
    return (n - 1) * math.factorial(n - 1) * n / 2


def solve(n: int) -> int:
    if n == 2:
        print('spacial case')
        return 1
    count = 0
    out = 0
    for i in range(1, n - 1):
        count += math.factorial(n) / (n - i)
        print(f'{i} occurs {count} times')
        out += i * count
    count += add(n) - f(n) * n
    print(f'{n - 1} occurs {count} times')
    out += (n - 1) * count
    return out

