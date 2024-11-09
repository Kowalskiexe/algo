#!/usr/bin/env python3


def main():
    n = int(input())
    for _ in range(n):
        line = input()
        x, y, t = line.split()
        x = int(x)
        y = int(y)
        t = int(t)
        m = [[0 for _ in range(x)] for _ in range(y)]
        k = 1

        for c in range(0, x, 2):
            for r in range(0, y, 3):
                if r + 1 >= y:
                    continue
                m[r][c] = k
                m[r + 1][c] = k
                k += 1

        for r in range((y + 1) // 3 * 3, y, 2):
            for c in range(0, x, 3):
                if c + 1 >= x:
                    continue
                m[r][c] = k
                m[r][c + 1] = k
                k += 1

        for i in range(y):
            for j in range(x):
                if (m[i][j] == 0):
                    print(".", end="")
                else:
                    print("X", end="")
            print()
        print()


if __name__ == "__main__":
    main()
