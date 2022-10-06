#!/bin/python

count = 0
for a in range(1, 5):
    for b in range(1, 5):
        if a == b:
            continue
        for c in range(1, 5):
            if a == c or b == c:
                continue
            for d in range(1, 5):
                if a == d or b == d or c == d:
                    continue
                count += 1
                print(f'4\n{a}{b}{c}{d}')
                with open(f'in/g{count}.in', 'w') as file:
                    file.write(f'4\n{a} {b} {c} {d}')

