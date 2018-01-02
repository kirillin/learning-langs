# Exapmle of using cython.

We have:

* `heavy_computations.pyx` contains some long-time computations;
* `comile_pyx.sh` example of compiling python scripts to C modules;
* `setup.py` example of automatic compiling your python scripts.

## What in `comile_pyx.sh`?

Compiling to C module using `cython` for <i>python 2</i> syntax:

	
```bash
$ cython -2 heavy_computations.pyx -o heavy_computations.c`
$ gcc -shared -pthread -fPIC -fwrapv -O2 -Wall -fno-strict-aliasing -lm -I/usr/include/python2.7/ -o heavy_calculations.so heavy_calculations.c
```    
    
<b>Note:</b> be careful and check versions of python!

## What in `setup.py` and how to use it?

```bash
$ python setup.py build_ext --inplace
```

then

```
$ python
Python 3.6.2
[GCC 7.2.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import pyximport
>>> pyximport.install()
>>> import heavy_calculations
``` 

Have fun!
