#!/bin/python

import subprocess

task = 'bom'
silent = False

for i in range(6):
    result = subprocess.run([f'./{task}.e < ./ocen/in/{task}{i}.in'], shell = True, text = True, capture_output = True).stdout
    # result = result.replace('\n', '')
    result = result.strip()
    out = subprocess.run([f'cat ./ocen/out/{task}{i}.out'], shell = True, text = True, capture_output = True).stdout
    # out = out.replace('\n', '')
    out = out.strip()
    if silent:
        print(f'{i}: passed: {"yes" if result == out else "NO"}')
    else:
        print(f'{i}: result: {result} out: {out} passed: {"yes" if result == out else "NO"}')

