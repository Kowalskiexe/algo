#!/usr/bin/env python

with open('input.txt', 'r') as file:
    i = 0
    sums = []
    s = 0
    for line in file:
        if line == '\n':
            sums.append(s)
            print(f'elf {i} has {s}')
            s = 0
            i += 1
        else:
            s += int(line)
    sums.append(s)
    i += 1
    sums.sort()
    out = sum(sums[-3:])
    print(out)

