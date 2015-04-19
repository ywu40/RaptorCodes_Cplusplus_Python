#!/usr/bin/env python

"""
setup_decoder.py file for raptor_decoder
"""

from distutils.core import setup, Extension


decoder_module = Extension('_raptor_decoder',
                           sources=['raptor_decoder_wrap.cxx', 'raptor_common.cpp',
                                    'raptor_configure.cpp', 'raptor_data.cpp',
                                    'raptor_decoder.cpp', 'raptor_decoder_api.cpp', 'raptor_triple.cpp'],
                           )

setup (name = 'raptor_decoder',
       version = '0.1',
       author      = "Yeqing Wu",
       description = """Raptor Decoder""",
       ext_modules = [decoder_module],
       py_modules = ["raptor_decoder"],
       )
