#!/bin/python

import subprocess

for i in range(0, 1000):
    result = subprocess.run([f'./ik.e < ./testy-kra/in/imp{i}.in'], shell = True, text = True, capture_output = True).stdout
    result = result.replace('\n', '')
    out = subprocess.run([f'cat ./testy-kra/out/imp{i}.out'], shell = True, text = True, capture_output = True).stdout
    out = out.replace('\n', '')
    print(f'{i}: resut: {result} out: {out} passed: {"yes" if result == out else "NO"}')

