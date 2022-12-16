#!/usr/bin/env python

import numpy as np

moves = open(0).read().split('\n')
del moves[-1]

moves = [m.split(' ') for m in moves]
moves = [(m[0], int(m[1])) for m in moves]

head_pos = np.array([0, 0])
tail_pos = np.array([0, 0])

move_vec = {
    'U': np.array([0, 1]),
    'D': np.array([0, -1]),
    'R': np.array([1, 0]),
    'L': np.array([-1, 0]),
}


def print_head_tail(head, tail, x, y):
    for i in range(y - 1, -1, -1):
        for j in range(x):
            cell = '.'
            if tail[0] == j and tail[1] == i:
                cell = 'T'
            if head[0] == j and head[1] == i:
                cell = 'H'
            print(cell, end='')
        print('')


visited = set()
print_head_tail(head_pos, tail_pos, 6, 6)
for move in moves:
    print(move)
    for step in range(move[1]):
        head_pos += move_vec[move[0]]
        diff = head_pos - tail_pos
        tail_vec = np.array([0, 0])
        if np.abs(diff[0]) >= 2 or np.abs(diff[1]) >= 2:
            if diff[0] in (1, 2):
                tail_vec[0] = 1
            if diff[0] in (-1, -2):
                tail_vec[0] = -1
            if diff[1] in (1, 2):
                tail_vec[1] = 1
            if diff[1] in (-1, -2):
                tail_vec[1] = -1
            tail_pos += tail_vec
        print(head_pos, tail_pos)
        print_head_tail(head_pos, tail_pos, 6, 6)
        visited |= {(tail_pos[0], tail_pos[1])}
print(visited)
print(len(visited))
