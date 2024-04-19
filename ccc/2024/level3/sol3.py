#!/usr/bin/env python3

def print_lawn(lawn):
    for line in lawn:
        print(''.join(line))

n = int(input())

for _ in range(n):
    x, y = [int(v) for v in input().split()]
    print(x, y)
    lawn = []
    for i in range(y):
        lawn.append(list(input().strip()))
    print_lawn(lawn)
    path = input().strip()
    print(path)
    cx = 0; cy = 0
    lawn[0][0] = 'v'
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

        if cy < 0 or cy >= y:
            succ = False
            print('out of bounds y')
            break
        if cx < 0 or cx >= x:
            succ = False
            print('out of bounds x')
            break
        if lawn[cy][cx] == 'X':
            succ = False
            print('tree')
            break
        if lawn[cy][cx] == 'v':
            # visited twice
            print('visited twice')
            succ = False
            break
        lawn[cy][cx] = 'v'  # mark as visited
    print_lawn(lawn)

    if succ:
        print('VALID')
    else:
        print('INVALID')
