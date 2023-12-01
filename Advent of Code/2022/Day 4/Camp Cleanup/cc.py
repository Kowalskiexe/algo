#!/usr/bin/env python

nested = 0
while True:
    try:
        line = input()
    except EOFError:
        break
    line = line.split(',')
    a = line[0].split('-')
    ab = int(a[0])
    ae = int(a[1])
    b = line[1].split('-')
    bb = int(b[0])
    be = int(b[1])
    if (ab <= bb and ae >= be) or (bb <= ab and be >= ae):
        nested += 1
print(nested)
