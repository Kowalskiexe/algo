#!/bin/python

def find_arith(seq: list, length: int):
    out = []
    for i in seq:
        seq.remove(i)
        for j in range(1, length):
            idx = seq.index(i + j)
            seq.remove(i + j)
        out.append(list(range(i, i + length)))
    print(f'remains: {seq}')
    return out

def pretty_print(fao: list):
    for i in fao:
        print(i)

