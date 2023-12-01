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

is_visible = np.zeros((y, x), dtype='bool')
is_visible[0, :] = True
is_visible[-1, :] = True
is_visible[:, 0] = True
is_visible[:, -1] = True

for i, row in enumerate(h[1:-1], start=1):
    for j, el in enumerate(row[1:-1], start=1):
        # from top
        is_visible[i, j] |= np.max(h[:i, j]) < h[i, j]
        # from bottom
        is_visible[i, j] |= np.max(h[i + 1:, j]) < h[i, j]
        # from left
        is_visible[i, j] |= np.max(h[i, :j]) < h[i, j]
        # from right
        is_visible[i, j] |= np.max(h[i, j + 1:]) < h[i, j]

print('visibility:')
print(is_visible)
print(np.count_nonzero(is_visible))
