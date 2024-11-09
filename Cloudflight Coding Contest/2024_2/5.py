#!/usr/bin/env python3


def has_neighbor(m: list[list[int]], y: int, x: int) -> bool:
    for c in range(max(0, x - 1), min(x + 2, len(m[0]))):
        for r in range(max(0, y - 1), min(y + 2, len(m))):
            if m[r][c] != 0:
                return True
    return False


def first_free(m: list[list[int]], orientation: int) -> tuple[int, int]:
    for y, r in enumerate(m):
        for x, _ in enumerate(r):
            if has_neighbor(m, y, x):
                continue
            if orientation == 0 and (y + 1 >= len(m) or has_neighbor(m, y + 1, x)):
                continue
            if orientation == 1 and (x + 1 >= len(m[0]) or has_neighbor(m, y, x + 1)):
                continue
            return y, x
    return -1, -1


def place(m: list[list[int]], orientation: int) -> tuple[int, int]:
    y, x = first_free(m, orientation)
    if y == -1 or x == -1:
        raise ValueError("No free space")
    if orientation == 0:
        m[y][x] = 1
        m[y + 1][x] = 1
        return y + 1, x
    elif orientation == 1:
        m[y][x] = 1
        m[y][x + 1] = 1
        return y, x + 1
    else:
        raise ValueError("Invalid orientation")


def num_to_orient(n: int, size: int) -> list[int]:
    s = bin(n)[2:]
    out =  [int(b) for b in s]
    if len(out) < size:
        out = [0] * (size - len(out)) + out
    return out


def print_m(m: list[list[int]]) -> None:
    y = len(m)
    x = len(m[0])
    for i in range(y):
        for j in range(x):
            if (m[i][j] == 0):
                print(".", end="")
            else:
                print("X", end="")
        print()
    print()


def main():
    n = int(input())
    for _ in range(n):
        line = input()
        x, y, t = line.split()
        x = int(x)
        y = int(y)
        t = int(t)

        o_id = 0
        m = [[0 for _ in range(x)] for _ in range(y)]
        succ = False
        while 2 ** t - 1 > o_id and not succ:
            orientations = num_to_orient(o_id, t)
            # print(orientations)
            succ = True
            for i, o in enumerate(orientations, start = 1):
                try:
                    yi, xi = place(m, o)
                    density = i * 2 / (x * (yi) + xi + 1)
                    target_density = t * 2 / (x * y) * i / len(orientations)
                    if density < target_density:
                        # print(density, target_density)
                        raise ValueError("Hera")
                    # print_m(m)
                except ValueError:
                    m = [[0 for _ in range(x)] for _ in range(y)]
                    succ = False
                    o_id += 1
                    break
            # print("o_id:", o_id)
        # print("done", o_id, succ)

        print_m(m)



if __name__ == "__main__":
    main()
