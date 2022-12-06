#!/usr/bin/env python

datastream = input()
for i, v, in enumerate(datastream):
    if len(set(datastream[i:i + 4])) == 4:
        print(i + 4)
        break
