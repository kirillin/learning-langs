#!/usr/bin/env python3
# coding: utf-8
"""
    Списки в Python это самое общее представление последовательостей.
    Предоставляют очень гибкие инструменты работы с собой -- списки объектов (например, файлов)
"""

l = [12, 'python', 3.14]
print(len(l))   # 3
print(l[0])     # 12
l[0] = 42
print(l)        # [12, 'python', 3.14]
print(l[:-1])   # [12, 'python']

l2 = l + [6, 7, 8]
print(l2)       # [12, 'python', 3.14, 6, 7, 8]

print(l*2)      # [12, 'python', 3.14, 12, 'python', 3.14]
print(l)        # [12, 'python', 3.14] -- not changed

" методы списков"
l.append('lol')
print(l)        # [12, 'python', 3.14, 'lol']
print(l.pop(1)) # 'python'
print(l)        # [12, 3.14, 'lol']

l.insert(1, 666)
print(l)        # [12, 666, 3.14, 'lol']
l.remove(666)
print(l)        # [12, 3.14, 'lol']

# some slow, better use numpy arrays
A = [ [1, 2, 3],
      [4, 5, 6],
      [7, 8, 9]]
print(A)    # [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print([row[0] for row in A])    # [1, 4, 7]
print([row[0] for row in A if row[0] % 2 == 0])    # [4]

diag = [A[i][i] for i in [0, 1, 2]]
print(diag)     # [1, 5, 9]

print([c * 2 for c in 'python'])    # ['pp', 'yy', 'tt', 'hh', 'oo', 'nn']

print(list(range(0, 10, 1)))        # [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

print([[x, x / 2, x * 2] for x in range(0,10, 1) if x % 2 == 0])
# [[0, 0.0, 0], [2, 1.0, 4], [4, 2.0, 8], [6, 3.0, 12], [8, 4.0, 16]]

# generator of row sum
G = (sum(row) for row in A)
print(next(G))  # 6
print(next(G))  # 15
print(next(G))  # 24

# map как генератор, позволяет запустить нечто (итерируемое) в функции
print(list(map(sum, A)))    # [6, 15, 24]   // in python 2 not need list(...)
print(list(map(round, [1.2, 1.7, 2.9])))    # [1, 2, 3]

print({sum(row) for row in A})  # {6, 15, 24}   // set
print({i: sum(A[i]) for i in range(3)})  # {0: 6, 1: 15, 2: 24} // dict

print([ord(x) for x in 'pythoon'])  # [112, 121, 116, 104, 111, 111, 110] // list -- all elements
print({ord(x) for x in 'pythoon'})  # {104, 110, 111, 112, 116, 121} // set -- only unique elements
print({x: ord(x) for x in 'pythoon'})   # {'p': 112, 'y': 121, 't': 116, 'h': 104, 'o': 111, 'n': 110} // dict -- keys are uniaue
print((ord(x) for x in 'pythoon'))      # <generator object <genexpr> at 0x7fda83c1a2b0>

















