#!/usr/bin/env python3
import sys


# for debugging
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def cover(src, corner, end):
    pass


def main():
    n = int(input())
    for t, _ in enumerate(range(n)):
        x, y = [int(v) for v in input().split()]
        eprint(x, y)
        tx = -1; ty = -1
        for i in range(y):
            line = input().strip()
            for j, ch in enumerate(line):
                if ch == 'X':
                    tx = j
                    ty = i
        eprint(tx, ty)

        # find odd dist to edge
        succ = False
        succ |= tx % 2 == 1
        succ |= ty % 2 == 1
        succ |= (x - tx + 1) % 2 == 1
        succ |= (y - ty + 1) % 2 == 1
        if not succ:
            print('wrong idea', t + 1)


if __name__ == '__main__':
    main()
