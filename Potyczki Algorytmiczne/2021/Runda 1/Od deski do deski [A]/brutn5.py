#!/bin/python

def gen(m: int) -> list:
    out = []
    
    # 2, 2, 2
    for a in range(1, m + 1):
        for b in range(1, m + 1):
            for c in range(1, m + 1):
                if a == b or a == c or c == b:
                    continue
                #print(a, a, b, b, c, c, sep = ', ', end = ' - 2, 2, 2\n')
                out.append([[a, a, b, b, c, c], '2, 2, 2'])

    
    # 3, 3
    for a in range(1, m + 1):
        for b in range(1, m + 1):
            if a == b:
                continue
            for a1 in range(1, m + 1):
                for b1 in range(1, m + 1):
                    #print(a, a1, a, b, b1, b, sep = ', ', end  = ' - 3, 3\n')
                    out.append([[a, a1, a, b, b1, b], '3, 3'])
    
    # 2, 4
    for a in range(1, m + 1):
        for b in range(1, m + 1):
            if a == b:
                continue
            for b1 in range(1, m + 1):
                for b2 in range(1, m + 1):
                    #print(a, a, b, b1, b2, b, sep = ', ' , end = ' - 2, 4\n')
                    out.append([[a, a, b, b1, b2, b], '2, 4'])
    
    # 4, 2
    for a in range(1, m + 1):
        for b in range(1, m + 1):
            if a == b:
                continue
            for a1 in range(1, m + 1):
                for a2 in range(1, m + 1):
                    #print(a, a1, a2, a, b, b, sep = ', ', end = ' - 4, 2\n')
                    out.append([[a, a1, a2, a, b, b], '4, 2'])
    
    # 6
    for a in range(1, m + 1):
        for a1 in range(1, m + 1):
            for a2 in range(1, m + 1):
                for a3 in range(1, m + 1):
                    for a4 in range(1, m + 1):
                        #print(a, a1, a2, a3, a4, a, sep = ', ', end = ' - 6\n')
                        out.append([[a, a1, a2, a3, a4, a], '6'])
    return out

# input must be sorted
# returns an index
def find_dup(t: list) -> list:
    dups = []
    for i, v in enumerate(t, 1):
        if i == len(t):
            break
        #print(t[i][0], v[0])
        if t[i][0] == v[0]:
            print(f'dup found {t[i][0]}, ({t[i][1]}); ({v[1]})')
            dups.append(i)
    return dups

def main():
    t = gen(5)
    t.sort()
    dups = find_dup(t)
    if len(dups) == 0:
        print('no dups')
    else:
        print(f'dups {len(dups)}')

if __name__ == '__main__':
    main()

