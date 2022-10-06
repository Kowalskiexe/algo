#!/bin/python

for i in range(1, 11):
    with open(f'in/k{i}', 'w') as file:
        print(i)
        for j in range(1, i + 1):
            print(j, end = ' ')
        print('')
        file.write(f'{i}\n')
        for j in range(1, i + 1):
            file.write(f'{j} ')

