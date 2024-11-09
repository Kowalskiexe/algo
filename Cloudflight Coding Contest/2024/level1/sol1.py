#!/usr/bin/env python3
n = int(input())

for _ in range(n):
    line = input().strip()
    counts = {'W': 0, 'D': 0, 'S': 0, 'A': 0}
    for ch in line:
        counts[ch] += 1
    # print(counts)
    print(counts['W'], counts['D'], counts['S'], counts['A'])
