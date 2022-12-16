#!/usr/bin/env python

import numpy as np

moves = open(0).read().split('\n')
del moves[-1]

moves = [m.split(' ') for m in moves]
moves = [(m[0], int(m[1])) for m in moves]

move_vec = {
    'U': np.array([0, 1]),
    'D': np.array([0, -1]),
    'R': np.array([1, 0]),
    'L': np.array([-1, 0]),
}


def print_head_tail(knots, positions, x, y):
    zipped = list(zip(positions, knots))
    zipped.reverse()
    for i in range(y - 1, -1, -1):
        for j in range(x):
            cell = '.'
            for pos, knot in zipped:
                if pos[0] == j and pos[1] == i:
                    cell = knot
            print(cell, end='')
        print('')


def get_step(tail_pos, head_pos):
    step = np.array([0, 0])
    diff = head_pos - tail_pos
    if np.abs(diff[0]) >= 2 or np.abs(diff[1]) >= 2:
        if diff[0] in (1, 2):
            step[0] = 1
        if diff[0] in (-1, -2):
            step[0] = -1
        if diff[1] in (1, 2):
            step[1] = 1
        if diff[1] in (-1, -2):
            step[1] = -1
    return step


visited = set()
knots = ['H', 1, 2, 3, 4, 5, 6, 7, 8, 9]
positions = [np.array([11, 5]) for _ in range(10)]
print_head_tail(knots, positions, 26, 21)
for move in moves:
    print(move)
    for step in range(move[1]):
        positions[0] += move_vec[move[0]]
        for i, knot in enumerate(knots[1:], start=1):
            step = get_step(positions[i], positions[i - 1])
            positions[i] += step
        print_head_tail(knots, positions, 26, 21)
        print('---')
        visited |= {(positions[-1][0], positions[-1][1])}
print(len(visited))
