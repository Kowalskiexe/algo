#!/bin/python

def sumOfDigits(n):
    s = 0
    while n != 0:
        s += n % 10
        n //= 10
    return s

def main():
    print('k:')
    k = int(input())
    
    print('digits:')
    digits = int(input())
    
    count = 0
    for i in range(0, 10**digits):
        if i % k == 0 and sumOfDigits(i) % k == 0:
            print(f'{i} OK')
            count += 1
        else:
            print(i)

    print(f'res: {count}')

if __name__ == '__main__':
    main()
    
