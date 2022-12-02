#!/usr/bin/env python

with open('input2.txt', 'r') as file:
    total_score = 0
    for line in file:
        op = ord(line[0]) - ord('A') + 1
        tactic = ord(line[2]) - ord('X')
        score = tactic * 3
        # 1 loses to 2,
        # 2 loses to 3,
        # 3 loses to 1
        # n loses to n % 3 + 1
        # n beats (n + 1) % 3 + 1
        if tactic == 0:  # lose
            score += (op + 1) % 3 + 1
        if tactic == 1:  # draw
            score += op
        if tactic == 2:  # win
            score += op % 3 + 1
        total_score += score
    print(total_score)
