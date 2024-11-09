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
        m = [[0 for _ in range(x)] for _ in range(y)]
        k = 1

        for c in range(0, x, 2):
            for r in range(0, y, 4):
                if r + 2 >= y:
                    continue
                m[r][c] = k
                m[r + 1][c] = k
                m[r + 2][c] = k
                k += 1

        for r in range((y + 1) // 4 * 4, y, 2):
            for c in range(0, x, 4):
                if c + 2 >= x:
                    continue
                m[r][c] = k
                m[r][c + 1] = k
                m[r][c + 2] = k
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
