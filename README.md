# RaptorCodes_Cplusplus_Python
In this project, we add Python APIs for Raptor encoder and decoder. In this way, the C++ codes can be called with Python APIs. 
In some projects, such as GNURadio and USRP board, the codes of the core, heavy time consuming parts are written by using C++. However, the upper level codes are written by Python because using Python can be more easily for testing and changing the configuration. In this project, we do the same way to expose the Pythoon APIs for upper level usage. We use SWIG to convert Raptor encode/decoder C++ APIs into Python APIs.

File raptor_encoder.i and raptor_decoder.i are the file for Raptor encoder/decoder C++ to Python conversion. These two files define which APIs will be exposed in Python level.

In order to convert these C++ API into Python APIs, we need to perform the following commands:

Encoder side:

1) sudo swig -c++ -python raptor_encoder.i

2) sudo python setup_encoder.py build_ext --inplace

Decoder side:

1) sudo swig -c++ -python raptor_decoder.i

2) sudo python setup_decoder.py build_ext --inplace

Then you can get the Python APIs. File run.py will show you an example of how to use these Raptor encoder/decoder Python APIs. Please make sure that you have installed Python before you perform the above steps.

Hope this can help you. If you have any questions, please let me know. Thanks.
