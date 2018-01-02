#!/usr/bin/bash

# need python-dev and python3-dev packages

cython -2 heavy_calculations.pyx
echo "heavy_calculations.pyx compiled by cython to heavy_calculations.c"

gcc -shared -pthread -fPIC -fwrapv -O2 -Wall -fno-strict-aliasing -lm -I/usr/include/python2.7/ -o heavy_calculations.so heavy_calculations.c
echo "heavy_calculations.c compiled by gcc"

cython -3 heavy_calculations.pyx -o heavy_calculations3.c
echo "heavy_calculations.pyx compiled by cython to heavy_calculations3.c"

gcc -shared -pthread -fPIC -fwrapv -O2 -Wall -fno-strict-aliasing -lm -I/usr/include/python3.5/ -o heavy_calculations.so heavy_calculations3.c
echo "heavy_calculations3.c compiled by gcc"
