#!/usr/bin/env python3

def print_lawn(lawn):
    for line in lawn:
        print(''.join(line))

def get_shape(trace):
    min_x = 10**9; max_x = -1
    min_y = 10**9; max_y = -1
    for y, line in enumerate(trace):
        for x, ch in enumerate(line):
            if ch == 'v':
                max_x = max(max_x, x)
                max_y = max(max_y, y)
                min_x = min(min_x, x)
                min_y = min(min_y, y)
    missing_fields = []
    for y in range(min_y, max_y + 1):
        for x in range(min_x, max_x + 1):
            if trace[y][x] == '.':
                missing_fields.append((y - min_y, x - min_x))
    dims = {
        'y': max_y - min_y + 1,
        'x': max_x - min_x + 1,
    }
    return dims, missing_fields


def get_tree_yx(lawn):
    for y, line in enumerate(lawn):
        for x, ch in enumerate(line):
            if ch == 'X':
                return y, x
    return -1, -1

n = int(input())

for _ in range(n):
    x, y = [int(v) for v in input().split()]
    # print(x, y)
    lawn = []
    for i in range(y):
        lawn.append(list(input().strip()))
    # print_lawn(lawn)

    path = input().strip()
    # print(path)

    trace_size = 200
    trace = [['.'] * trace_size for _ in range(trace_size)]
    cx = trace_size // 2; cy = trace_size // 2
    trace[cy][cx] = 'v'
    succ = True
    for ch in path:
        if ch == 'W':
            cy -= 1
        if ch == 'S':
            cy += 1
        if ch == 'A':
            cx -= 1
        if ch == 'D':
            cx += 1

        if trace[cy][cx] == 'v':
            # visited twice
            # print('visited twice')
            succ = False
            break
        trace[cy][cx] = 'v'  # mark as visited

    # print_lawn(trace)
    shape, missing = get_shape(trace)
    # print(shape, missing)

    if shape['x'] != x:
        # print('out of bounds x')
        succ = False
    if shape['y'] != y:
        # print('out of bounds x')
        succ = False
    if len(missing) != 1:
        # print('didnt cover all fields')
        succ = False
    else:
        my, mx = missing[0]
        ty, tx = get_tree_yx(lawn)
        if my != ty or mx != tx:
            # print('tree collision')
            succ = False

    if succ:
        print('VALID')
    else:
        print('INVALID')
