#!/usr/bin/env python3
# coding: utf-8

X = set('python')
Y = {'h', 'y', 'o'}

print(X, Y)     # ({'h', 'n', 'y', 'o', 't', 'p'}, {'h', 'o', 'y'}) ??
print(X & Y)    # {'h', 'y', 'o'}   // intersection
print(X | Y)    # {'h', 'n', 'y', 'o', 't', 'p'}    // union
print(X - Y)    # {'n', 't', 'p'}   // difference
print(X > Y)    # True  //superset

# filtering duplicates
print(list(set([1, 2, 1, 1, 2, 3, 4]))) # [1, 2, 3, 4]
print(set('python') == set('ypthon'))   # True
print(set('123456') - set('11234'))     # {'5', '6'}

print('p' in set('spam'), 'p' in 'spam', 'ham' in ['eggs', 'spam', 'ham'])     # (True, True, True)

print(1 / 3)                # 0.3333333333333333
print((2 / 3) + (1 / 2))    # 1.1666666666666665

import decimal

d = decimal.Decimal('3.141')
print(d + 1)                # 4.141

decimal.getcontext().prec = 2
res = decimal.Decimal('1.00') / decimal.Decimal('3.00')
print(res)                  # 0.33

from fractions import Fraction

f = Fraction(2, 3)
f = f + 1
print(f)    # 5/3

# booleans

b = 1 > 2, 5 > 0
print(b)                # (False, True)
print(bool('python'))   # True

X = None
print(X)        # None

L = [None] * 5
print(L)        # [None, None, None, None, None]

# type object

print(type(L))          # <class 'list'>
print(type(type(L)))    # <class 'type'>
"""
# for Python 2.X

print(type(L))          # <type 'list'>
print(type(type(L)))    # <type 'type'>
"""

if type(L) == type([]): print('yes')        # yes
if type(L) == list: print('yes')            # yes
if isinstance(L, list): print('yes')        # yes

