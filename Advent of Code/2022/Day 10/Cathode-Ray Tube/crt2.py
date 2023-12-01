#!/usr/bin/env python

operations = open(0).read().split('\n')
del operations[-1]
operations = [op.split(' ') for op in operations]

X = [1]
carry = 0
for op in operations:
    X.append(X[-1] + carry)
    if carry != 0:
        carry = 0

    if op[0] == 'addx':
        arg = int(op[1])
        X.append(X[-1])
        carry = arg


def print_sprite(x):
    for i in range(40):
        if abs(x - i) <= 1:
            print('#', end='')
        else:
            print('.', end='')
    print('')


def print_crt(crt):
    for i, pix in enumerate(crt):
        print(pix, end='')
        if (i + 1) % 40 == 0:
            print('')


crt = []
for i, x in enumerate(X[1:], start=1):
    print(f'{i}th {x}')
    print('sprite:')
    print_sprite(x)
    crt_pos = len(crt) % 40
    if abs(x - crt_pos) <= 1:
        crt.append('#')
    else:
        crt.append('.')
    print('current crt:')
    print_crt(crt)
    print('')

print_crt(crt)
