#!/usr/bin/env python3
# coding: utf-8
"""
Numbers, strings, lists, dictionaries, tuples, files, and sets are generally considered
to be the core object (data) types. Types, None , and Booleans are sometimes clas-
sified this way as well. There are multiple number types (integer, floating point,
complex, fraction, and decimal) and multiple string types (simple strings and Uni-
code strings in Python 2.X, and text strings and byte strings in Python 3.X).

They are known as “core” types because they are part of the Python language itself
and are always available; to create other objects, you generally must call functions
in imported modules. Most of the core types have specific syntax for generating
the objects: 'spam' , for example, is an expression that makes a string and deter-
mines the set of operations that can be applied to it. Because of this, core types are
hardwired into Python’s syntax. In contrast, you must call the built-in open function
to create a file object (even though this is usually considered a core type too).

An “immutable” object is an object that cannot be changed after it is created.
Numbers, strings, and tuples in Python fall into this category. While you cannot
change an immutable object in place, you can always make a new one by running
an expression. Bytearrays in recent Pythons offer mutability for text, but they are
not normal strings, and only apply directly to text if it’s a simple 8-bit kind (e.g.,
ASCII).

A “sequence” is a positionally ordered collection of objects. Strings, lists, and tuples
are all sequences in Python. They share common sequence operations, such as
indexing, concatenation, and slicing, but also have type-specific method calls. A
related term, “iterable,” means either a physical sequence, or a virtual one that
produces its items on request.

The term “mapping” denotes an object that maps keys to associated values.
Python’s dictionary is the only mapping type in the core type set. Mappings do not
maintain any left-to-right positional ordering; they support access to data stored
by key, plus type-specific method calls.

“Polymorphism” means that the meaning of an operation (like a + ) depends on the
objects being operated on. This turns out to be a key idea (perhaps the key idea)
behind using Python well—not constraining code to specific types makes that code
automatically applicable to many types.

    Программа на Python состоит из модулей, инструкции и выражений:
        1) Программа состоит из модулей;
        2) Модули включают в себя инструкции;
        3) Инструкции включают в себя выражения;
        4) Выражения создают и обрабатывают объекты.

    Встроенные типы данных:
        1) удобно использовать (lists, dictionaries, sets);
        2) легко расширить функциональность;
        3) чаще всего более эффективны, нежели самописные структуры данных;
        4) явяются стандартными типами языка.

    Базовые типы:
        1) 3, 3.14, 3+4j, 0b011, Decimal(), Fraction();
        2) 'spam', "Bob's", b'a\x04c', u'sp\xc4m;
        3) [1, 2, [4, 'five']], list(range(10));
        4) {'one' : 1, 'two' : 2}, dict(one=1, two=2);
        5) (1, 2, 'three'), tuple(1,2,3);
        6) set(1, 2, 3), {1, 2, 3};
        7) open('filename.txt'), open(r'/home/username/filename.txt', 'wb);
        8) True, False, None, types;
        9) functions, modules, classes;
        10) compile code, stack tracebacks
"""

# Nummbers
print(3 + 6)        # 246
print(1.5 * 6)      # 9.0
print(3 ** 2)       # 9
print(3. ** 2)      # 9.0

print(0b110 + 0b001)    # 7 (bin(7) == 0b111)
print(0xAC + 0x01)      # 173 (hex(173) == 0xAD)

a = 3 + 4j
b = 2 + 3j
print(a+b, a*b, a/b)











