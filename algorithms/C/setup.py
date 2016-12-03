from distutils.core import setup, Extension

setup(name='math_tools', version='1.0',  \
      ext_modules=[Extension('math_tools', ['math_tools.c'])])