#!/bin/python

import subprocess as sp

for i in range(1, 101):
    out = sp.run([f'./odd.e < odd/in/{i}.in'], shell=True, text=True, capture_output=True).stdout
    out = out.strip()
    cor = sp.run([f'cat odd/out/{i}.out'], shell=True, text=True, capture_output=True).stdout
    cor = cor.strip()
    print(f'{i}: out:\t{out}\tcor:\t{cor}\tpassed:{"yes" if cor == out else "NO"}')

