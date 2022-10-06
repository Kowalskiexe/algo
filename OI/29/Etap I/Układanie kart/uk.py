#!/bin/bash

import math

# m = n - 1

# get the arithmetic sum from frm to to with step = 1
def arith_sum(frm: int, to: int):
    count = to - frm + 1
    return int((frm + to) / 2 * count)

# get the arithmetic sum from 1 to idx inclusively
def multi_arith_sum(m: int, idx: int) -> int:
    full_frags = idx // m
    rest_count = idx - full_frags * m
    return full_frags * arith_sum(1, m) + arith_sum(m - rest_count + 1, m)

# get the value at idx index, counting from 1 inclusively
def el(m: int, idx: int) -> int:
    idx -= 1
    idx %= m
    return m - idx

def missing_weight(base: int, weight: int) -> int:
    return base - base // weight * weight

# helping function
def S(m: int, base: int, level: int) -> int:
    weight = 1
    count = base
    result = 0
    for i in range(level):
        print(f'\tlevel: {level - i}')
        print(f'\tweight: {weight} count: {count}')
        if base % weight == 0:
            print('\t\tbase is divisieble by weight')
            result += multi_arith_sum(m, count) * weight
            print(f'\t\tm_a_s {multi_arith_sum(m, count)} * {weight}')
        else:
            print('\t\tbase is not divisieble by weight')
            result += multi_arith_sum(m, count - 1) * weight
            print(f'\t\tm_a_s {multi_arith_sum(m, count - 1)} * {weight}')
            result += el(m, count) * missing_weight(base, weight)
            print(f'\t\tel {el(m, count)} * {missing_weight(base, weight)}')
        count = max(1, math.ceil(count / m))
        weight = min(weight * m, base)
        print(f'\tresult: {result}\n')
    return result

def solve(n: int) -> int:
    m = n - 1
    max_base = math.factorial(m)
    #base = max_base
    base = 1

    result = 0
    for i in range(1, n + 1):
        print(f'level {i}')
        result += S(m, base, i)
        base = min(base * m, max_base)
        print(f'{result = }')

    result -= n * m

    return result
