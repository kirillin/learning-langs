from distutils.core import setup
from Cython.Build import cythonize

setup(
 name='heavy',
 ext_modules = cythonize('heavy_calculations.pyx'),
)
