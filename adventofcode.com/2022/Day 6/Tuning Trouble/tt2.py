#!/usr/bin/env python

datastream = input()
for i, v, in enumerate(datastream):
    if len(set(datastream[i:i + 14])) == 14:
        print(i + 14)
        break
