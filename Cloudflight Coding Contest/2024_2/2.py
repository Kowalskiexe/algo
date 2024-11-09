#!/usr/bin/env python3


def main():
    n = int(input())
    for _ in range(n):
        line = input()
        x, y, t = line.split()
        x = int(x)
        y = int(y)
        t = int(t)
        # t // 3
        i = 1
        for _ in range(y):
            for _ in range(x // 3):
                print(i, i, i, end=" ")
                i += 1
            print()
        print()


if __name__ == "__main__":
    main()
