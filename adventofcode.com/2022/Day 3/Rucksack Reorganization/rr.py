#!/usr/bin/env python

def priority(letter):
    out = ord(letter)
    if letter <= 'Z':  # uppercase
        out = out - ord('A') + 27
    else:  # lowercase
        out = out - ord('a') + 1
    return out


with open('input.txt', 'r') as file:
    total_priority = 0
    for line in file:
        line = line[:-1]  # remove newline
        n = len(line) // 2
        left_dict = {}
        for letter in line[:n]:
            left_dict[letter] = left_dict.get(letter, 0) + 1
        right_dict = {}
        for letter in line[n:]:
            right_dict[letter] = right_dict.get(letter, 0) + 1
        for letter in left_dict:
            if letter in right_dict:
                total_priority += priority(letter)
    print(total_priority)
