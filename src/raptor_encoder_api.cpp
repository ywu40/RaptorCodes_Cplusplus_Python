#include <stdio.h>
#include "raptor_encoder_api.h"

using std::vector;

void RaptorEncoder::set_data(const std::string &raw_data)
{
        vector<unsigned char> vecData;
        stringToVector(raw_data, vecData);

  size_t data_size = vecData.size();
  U8 *data_buf = new U8[data_size];
  for (size_t i = 0; i < data_size; ++i)
  {
    data_buf[i] = raw_data[i];
  }
  
  CData data(data_buf, data_size);
  encoder->AddData(&data);

  delete[] data_buf;
  data_buf = NULL;
}

void RaptorEncoder::stringToVector(const std::string &strData,
                            std::vector<unsigned char> &vecData)
{
    vecData.resize(strData.size());
    // convert the string to a vector<unsigned char>
    for(unsigned int i = 0; i < strData.size(); i++) 
    {
        vecData[i] = static_cast<unsigned char>(strData[i]);
    }
}

void RaptorEncoder::get_data_access()
{
  while (!encoder->encoded_sym.empty())
  {
    encodedSym.push(encoder->encoded_sym.front());
    encoder->encoded_sym.pop();
  }
}

vector<U8> RaptorEncoder::get_encodedSym()
{
  CData data = encodedSym.front();
  encodedSym.pop();

  vector<U8> res;
  U8 *buf = data.GetData();
  int data_size = data.GetLen();
  for (U32 j = 0; j < data_size; ++j)
  {
    res.push_back(buf[j]);
  }

  return res;
}

bool RaptorEncoder::is_empty()
{
  return encodedSym.empty();
}

int RaptorEncoder::count_encodedSym()
{
  return encodedSym.size();
}
