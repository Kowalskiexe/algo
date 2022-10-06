#!/bin/python

import subprocess

for i in range(1, 2001):
    result = subprocess.run([f'./mon.e < ./montazysta2k/in/{i}.in'],
            shell = True,
            capture_output = True,
            text = True).stdout
    result = result.split('\n')[0]
    result = result.strip()
    correct_file = open(f'./montazysta2k/out/{i}.out', 'r') 
    correct_output = correct_file.readline()
    correct_output = correct_output.strip()
    correct_file.close()
    print(f'{i}: result: {result}, correct: {correct_output}, passed: {"yes" if result == correct_output else "NO"}')
