#!/usr/bin/env python

def priority(letter):
    out = ord(letter)
    if letter <= 'Z':  # uppercase
        out = out - ord('A') + 27
    else:  # lowercase
        out = out - ord('a') + 1
    return out


total_priority = 0
while True:
    try:
        line0 = input()
        line1 = input()
        line2 = input()
    except EOFError:
        break
    set0 = set(line0)
    set1 = set(line1)
    set2 = set(line2)
    for letter in set0:
        if letter in set1 and letter in set2:
            total_priority += priority(letter)
print(total_priority)
