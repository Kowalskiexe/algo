#!/usr/bin/env python

with open('input.txt', 'r') as file:
    total_score = 0
    for line in file:
        op = ord(line[0]) - ord('A') + 1
        my = ord(line[2]) - ord('X') + 1
        score = my
        # 1 loses to 2,
        # 2 loses to 3,
        # 3 loses to 1
        # n loses to n % 3 + 1
        if op == my:  # draw
            score += 3
        if op % 3 + 1 == my:  # win
            score += 6
        total_score += score
    print(total_score)
