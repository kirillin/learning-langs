#!/usr/bin/env python3
# coding: utf-8
"""
    Словари это нечто абсолютно другое (привет Монти Пайтон)
    Словари это не последовательности (sequence), а отображения или сопоставления (mappings)
    Хранят также коллекции объектов, но по ключу, вмето относительной позиции
"""

D = {'food': 'Spam', 'quantity': 4, 'color': 'pink'}
print(D['food'])        # 'Spam'
D['quantity'] += 1
print(D['quantity'])    # 5

D = {}
D['name'] = 'Margarita'
D['age'] = 24
print(D)        # {'name': 'Margarita', 'age': 24}

Margo = dict(name='Margarita', age=24)
print(Margo)    # {'name': 'Margarita', 'age': 24}

print(dict(zip(['name', 'age'], ['Margarita', 24])))    # {'name': 'Margarita', 'age': 24}

rec = {
    'name': {'first': 'unknown', 'last': 'Margarita'},
    'age': 24,
    'personality': ['beautiful', 'awesome']
}

print(rec)          # {'name': {'first': 'unknown', 'last': 'Margarita'}, 'age': 24}
print(rec['name'])  # {'first': 'unknown', 'last': 'Margarita'}
print(rec['name']['last'])      # Margarita
print(rec['personality'][-1])   # 'awesome'
rec['personality'].append('mad')
print(rec)  # {'name': {'first': 'unknown', 'last': 'Margarita'}, 'age': 24, 'personality': ['beautiful', 'awesome', 'mad']}

D = {'c': 3, 'a': 1, 'b': 2}
D['d'] = 4
# print(D['e'])     # KeyError
if not 'e' in D:
    print('missing')
D.get('a', 0)

Ks = list(D.keys())
Ks.sort()

for key in Ks:
    print(key, '=>', D[key])    # sorted dict

for key in sorted(D):
    print(key, '=>', D[key])    # sorted dict

x = 4
while x > 0:
    print('python!' * x)
    x -= 1
