#!/usr/bin/env python

operations = open(0).read().split('\n')
del operations[-1]
operations = [op.split(' ') for op in operations]

sig_strength = [1]
carry = 0
for op in operations:
    sig_strength.append(sig_strength[-1] + carry)
    if carry != 0:
        carry = 0

    if op[0] == 'addx':
        arg = int(op[1])
        sig_strength.append(sig_strength[-1])
        carry = arg


total = 0
for i in range(20, len(sig_strength), 40):
    print(f'{i}th {sig_strength[i]} = {i * sig_strength[i]}')
    total += i * sig_strength[i]
print(total)
