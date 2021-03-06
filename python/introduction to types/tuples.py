#!/usr/bin/env python3
# coding: utf-8
"""
    Тюпл -- это неизменяемый список, является последовательностью.
    Используются для представления неизменяемых списков (календарь, года,
        личные данные).
    ps. те же списки, но неизменяемые, следователньо и функций для
            использования меньше, чем у списков. Может показаться, что
                они не нужны, но они нужны!
"""

T = (1, 2, 3, 4, 5)
print(len(T))       # 5

T = T + (6, 7)
print(T)            # (1, 2, 3, 4, 5, 6, 7)Ы
print(T[0])         # 1
print(T.index(1))   # 0
print(T.count(1))   # 1

T = T + (1,)
print(T)            # (1, 2, 3, 4, 5, 6, 7, 1)
print(T.count(1))   # 2

# T[0] = 42           # TypeError: tuples are immutable
print((-13,) + T[1:])  # (-13, 2, 3, 4, 5, 6, 7, 1)

T = 'spam', 3.0, [11, 22, 33]
print(T)            # ('spam', 3.0, [11, 22, 33])
print(T[1])         # 3.0
print(T[2][1])      # 22
T[2].append(42)
print(T)            # ('spam', 3.0, [11, 22, 33, 42])

