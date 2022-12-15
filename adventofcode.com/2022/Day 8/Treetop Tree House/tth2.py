#!/usr/bin/env python

import numpy as np

input_raw = open(0).read().split('\n')
del input_raw[-1]

x = len(input_raw[0])
y = len(input_raw)

h = np.zeros((y, x), dtype='int64')

for i, row in enumerate(input_raw):
    for j, el in enumerate(row):
        h[i, j] = int(el)
print('trees:')
print(h)

result = -1
for i, row in enumerate(h[1:-1], start=1):
    for j, el in enumerate(row[1:-1], start=1):
        # top
        d = i - 1
        while d >= 1 and h[d, j] < h[i, j]:
            d -= 1
        top = abs(i - d)

        # bottom
        d = i + 1
        while d < y - 1 and h[d, j] < h[i, j]:
            d += 1
        bottom = abs(i - d)

        # left
        d = j - 1
        while d >= 1 and h[i, d] < h[i, j]:
            d -= 1
        left = abs(j - d)

        # right
        d = j + 1
        while d < x - 1 and h[i, d] < h[i, j]:
            d += 1
        right = abs(j - d)

        score = top * bottom * left * right
        print(f'{i} {j}: {top} {bottom} {left} {right}')
        result = max(result, score)
print(result)
