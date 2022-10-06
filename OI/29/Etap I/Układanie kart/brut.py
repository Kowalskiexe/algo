#!/bin/python

import math
import sys

def next_permutation(per: list) -> list:
    for i in range(len(per) - 2, -1, -1):
    #for i, v in enumerate(per[:-2:-1]):
        if per[i] < per[i + 1]:
            for j in range(len(per) - 1, -1, -1):
            #for j, w in enumerate(per[::-1]:
                if per[j] > per[i]:
                    tmp = per[i]
                    per[i] = per[j]
                    per[j] = tmp
                    per[i + 1:] = per[i + 1:][::-1]
                    return per
            return per
    if i == 0:
        per = per[::-1]
    return per

def to_list(n: int) -> list:
    l = []
    while n > 0:
        digit = n % 10
        n //= 10
        l.insert(0, digit)
    return l

def is_sorted(n: list) -> bool:
    for i, v in enumerate(n):
        if v != i + 1:
            return False
    return True

def step(n: list) -> (list, int):
    target = len(n) if n[0] == 1 else n[0] - 1
    for i, v in enumerate(n[1:], 1):
        if v == target:
            n.remove(target)
            n.insert(0, target)
            #print(n)
            return n, i
    raise Exception(f'no {target} in the list')

def process_permutation(per: list) -> int:
    per = per.copy()
    whole_cost = 0
    print(f'{per} ', end = '')
    while not is_sorted(per):
        per, cost = step(per)
        #print(f'-> {per} ({cost})', end = '')
        print(f'-> ({cost})', end = '')
        whole_cost += cost
    print()
    return whole_cost

def process(n: int) -> None:
    n_list = list(range(1, n + 1))
    costs = []
    for i in range(math.factorial(n)):
        per_cost = process_permutation(n_list)
        print(f'{n_list} cost: {per_cost}')
        costs.append(per_cost)
        n_list = next_permutation(n_list)

    print(f'all cost {sum(costs)}\n{costs}\n{sorted(costs)}')
    costs.sort()
    last = costs[1]
    strike = 1
    counts = []
    for i in costs[2:]:
        if i == last:
            strike += 1
        else:
            counts.append([last, strike])
            strike = 1
        last = i
    counts.append([last, strike])
    counts.sort()
    for num, occ in counts:
        print(f'{num}, {occ}')
    print()

mn = 6
if len(sys.argv) != 1:
    mn = int(sys.argv[1])

for i in range(2, mn + 1):
    print(f'i: {i}')
    process(i)

