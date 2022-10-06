#!/bin/python

import subprocess

for i in range(1, 5001):
    out = subprocess.run([f'./uk.e < karty/in/ukl{i}.in'], text = True, shell = True, capture_output = True).stdout
    out = out.strip()
    correct = subprocess.run([f'cat karty/out/ukl{i}.out'], text = True, shell = True, capture_output = True).stdout
    correct = correct.strip()
    print(f'{i} out: {out} correct: {correct} passed: {"yes" if out == correct else "NO"}')

