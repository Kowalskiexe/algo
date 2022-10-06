#!/bin/python

import subprocess as sp

# end inclusively
def test(start: int, end: int, path: str, pref: str, terse: bool):
    for i in range(start, end + 1):
        out = sp.run([f'./pan.e < {path}/in/{pref}{i}.in'], shell=True, text=True, capture_output=True).stdout.strip()
        cor = sp.run([f'cat {path}/out/{pref}{i}.out'], shell=True, text=True, capture_output=True).stdout.strip()
        if terse:
            print(f'{i}: out:\nn{out}\ncor:{cor}\nRESULT: {"yes" if out == cor else "NO"}')
        else:
            print(f'{i}: {"yes" if out == cor else "NO"}')

def run_small():
    test(0, 39, 'panall', 'pan', terse=False)

def run_big():
    test(1, 200, '', '', terse=False)

