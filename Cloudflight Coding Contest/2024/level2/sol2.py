#!/usr/bin/env python3
n = int(input())

for _ in range(n):
    line = input().strip()
    x = 0; y = 0
    min_x = 0; max_x = 0
    min_y = 0; max_y = 0
    for ch in line:
        if ch == 'W':
            y +=1
        if ch == 'S':
            y -= 1
        if ch == 'D':
            x += 1
        if ch == 'A':
            x -= 1
        min_x = min(x, min_x)
        max_x = max(x, max_x)
        min_y = min(y, min_y)
        max_y = max(y, max_y)
    out_x = abs(min_x) + max_x + 1
    out_y = abs(min_y) + max_y + 1
    print(out_x, out_y)
