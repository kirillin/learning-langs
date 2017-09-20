#!/usr/bin/env python3
# coding: utf-8
"""
    Объект File это главный инструмент для работы с внешними фалами, как то:
        текстовые документы, excel-файлы, айдио, видео и прочие.
"""

# create a text output file
file = open('data.txt', 'w')
file.write("I'm a robot!\n")
file.close()

# open file for read (default mode)
file = open('data.txt')
s = file.read()
print(s)        # I'm a robot!\n"
file.close()

# reads line by line
for line in open('data.txt'): print(line)

"BINARY BYTES FILES"
import struct

packed = struct.pack('>i6sh', 7, b'python', 8)
print(packed)               # b'\x00\x00\x00\x05python\x00\x05'

file = open('data.bin', 'wb')
print(file.write(packed))   # 12
file.close()


data = open('data.bin', 'rb').read()
print(data)                 # b'\x00\x00\x00\x05python\x00\x05'
print(data[4:10])            # b'python'
print(list(data))           # [0, 0, 0, 7, 112, 121, 116, 104, 111, 110, 0, 8]
print(struct.unpack('>i6sh', data))  # (7, b'python', 8)

"UNICODE TEXT FILES"
s = 'pyth\xf4n'
print(s)        # 'pythôn'

file = open('unidata.txt', 'w', encoding='utf-8')
print(file.write(s))        # 6
file.close()

data = open('unidata.txt', encoding='utf-8').read()
print(data)         # 'pythôn'
print(len(data))    # 6

s = s.encode('utf-8')
print(s)                    # b'pyth\xc3\xb4n'
print(s.decode('utf-8'))    # 'pythôn'

"""
# for python 2.X -- unicode need
import codecs

s = codecs.open('unidata.txt', encoding='utf8').read()
print(s)        # u'pyth\xf4n'      // decoded text

s = open('unidata.txt', 'rb').read()
print(s)        # 'pyth\xc3\xb4n'   // raw bytes, undecoded

s = open('unidata.txt').read()
print(s)        # 'pyth\xc3\xb4n'   // raw bytes, undecoded
"""

