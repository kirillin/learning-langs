#!/usr/bin/env python3
# coding: utf-8
"""
    Строки могут быть как текстом, так и послеовательностью байтов.
    Строка в Python это последоватльность однобуквенных строк.
"""
s = 'python'
length = len(s)     # 6
first_letter = s[0] # 'p'
last = s[-1]        # 'n'
last2 = s[len(s)-1] # 'n'
pre_last = s[-2]    # 'o'

th = s[2:4]         # 'th'
thon = s[2:]        # 'thon'
py = s[:2]          # 'py'
pytho = s[:-1]      # 'pytho'   may be useful for lists
python = s[:]       # 'python'

new_s = s + 'python'    # 'pythonpython'
new_s2 = s * 2          # 'pythonpython'

# Immutability
"""
    1) числа, строки и tuple -- неизменяемые объекты;
    2) списки, словари и множества -- изменяемые
"""
# s[0] = 'c'              # TypeError: 'str' object does not support item assignment
s = 'c' + s[1:]         # 'cython'

"перый способ изменения строки"
list_s = list(s)        # ['c', 'y', 't', 'h', 'o', 'n']
list_s[0] = 'p'
s = ''.join(list_s)     # 'python'

"второй способ изменения строки. Только для символов по 8 бит (ASCII)"
b = bytearray(s.encode('ascii'))
print(b)                # bytearray(b'python')
b.extend(b' is awesome!')
print(b)                # bytearray(b'python is awesome!')
print(b.decode())       # u'python is awesome!'

" методы объекта строка"

print(s.find('th'))             # 2
print(s.replace('th', 'TH'))    # 'pyTHon'
print(s)                        # 'python'

line = '1,2,3,4,5,6'
print(line.split(','))          # ['1', '2', '3', '4', '5', '6']
print(s.upper())                # 'PYTHON'
print(s.lower())                # ''
print(s.isalpha())              # True
print(s.isdigit())              # False

line = '1,2,3,4,5\r\n'
print(line.rstrip())            # '1,2,3,4,5'

# formatting strings
print('%s, %s and %s' % (s, s, s))                          # 'python, python and python'
print('{2}, {1} and {0}'.format('zero', 'one', 'two'))      # 'two, one and zero'
print('{}, {} and {}'.format('zero', 'one', 'two'))         # 'zero, one and two'

# formatting nums
print('{:,.4f} -- {:.0f}'.format(3243243.323, 3.14))            # '3,243,243.3230 -- 3'
print('%.2f | %+05d | %d | %s' % (3.14159, -42, 13, 'python'))  # '3.14 | -0042 | 13 | python'

print(s + '!')          # 'python!'
print(s.__add__('!'))   # 'python!'

# other methods of code strings
q = '\tpython\n'
print(len(q))       # 8
print(ord('\n'))    # 10
q = '\0python\0'
print(len(q))       # 5 // because \0 binary zero byte, does not terminate string
print(q)            # '\x00python\x00'

# unicode strings (NEED MORE DETAILED TOLD)
print('pyth\xf4n')  # 'pythôn'
print(u'pyth\u00f4n')  # 'pythôn'
print('python'.encode('utf8'))      # b'python'
print('python'.encode('utf16'))     # b'\xff\xfep\x00y\x00t\x00h\x00o\x00n\x00'
print('pyth\xf4\u00f4\U000000f4n')    # 'spÄÄÄm' // \u -- short, \U -# ξ = ['lol', 'kek', 'ahaha', 'xdd', '']
# print(ξ)

x = u'x'
y = b'y'
# print(x + y)          # fails in python 3 and works in python 2
print(x + y.decode())   # 'xy'
print(x + 'y')          # 'xy'
print('x'.encode() + y) # b'xy'

# pattern matching
import re
match = re.match('Hello[ \t]*(.*)world', 'Hello     Python world')
print(match.group(1))   # 'Python'

match = re.match('[/:](.*)[/:](.*)[/:](.*)', '/home/kirix:python')
print(match.groups())   # ('home', 'kirix', 'python')

sp = re.split('[/:]', '/home/kirix:python')
print(sp)               # ('home', 'kirix', 'python')
