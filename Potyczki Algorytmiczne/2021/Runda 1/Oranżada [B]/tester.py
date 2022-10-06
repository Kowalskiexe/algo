#!/bin/python

import subprocess

for i in range(1, 1001):
    out = subprocess.run([f'./ora.e < in/{i}.in'], shell=True, text=True, capture_output=True).stdout
    out = out.strip()
    cor = subprocess.run([f'cat out/{i}.out'], shell=True, text=True, capture_output=True).stdout
    cor = cor.strip()
    print(f'{i}: out: {out} cor: {cor}, passed: {"yes" if out == cor else "NO"}')

