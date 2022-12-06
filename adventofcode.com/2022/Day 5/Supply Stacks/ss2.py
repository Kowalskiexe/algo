#!/usr/bin/env python

rows = []
while True:
    row = input()
    if row == '':
        break
    rows.insert(0, row)
del rows[0]  # remove numbers under stacks
columns = int((len(rows[2]) + 1) / 4)

stacks = []
for i in range(columns):
    stacks.append([])
    idx = i * 4 + 1
    for r in rows:
        if r[idx] != ' ':
            stacks[i].append(r[idx])

while True:
    try:
        command = input()
    except EOFError:
        break
    command = command.split(' ')
    q = int(command[1])
    src = int(command[3]) - 1
    dest = int(command[5]) - 1

    top = stacks[src][-q:]
    stacks[dest] += top
    del stacks[src][-q:]

for stack in stacks:
    print(stack[-1], end='')
print()
