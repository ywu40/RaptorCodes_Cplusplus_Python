#!/usr/bin/env python

"""
setup_encoder.py file for raptor_encoder
"""

from distutils.core import setup, Extension


encoder_module = Extension('_raptor_encoder',
                           sources=['raptor_encoder_wrap.cxx', 'raptor_common.cpp',
                                    'raptor_configure.cpp', 'raptor_data.cpp',
                                    'raptor_encoder.cpp', 'raptor_encoder_api.cpp', 'raptor_triple.cpp'],
                           )

setup (name = 'raptor_encoder',
       version = '0.1',
       author      = "Yeqing Wu",
       description = """Raptor Encoder""",
       ext_modules = [encoder_module],
       py_modules = ["raptor_encoder"],
       )
