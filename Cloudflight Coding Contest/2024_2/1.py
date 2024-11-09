#!/usr/bin/env python3


def main():
    n = int(input())
    for _ in range(n):
        line = input()
        x, y = line.split()
        x = int(x)
        y = int(y)
        print(x // 3 * y)


if __name__ == "__main__":
    main()
