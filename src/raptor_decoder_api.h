#ifndef __RAPTOR_DECODER_API_H_
#define __RAPTOR_DECODER_API_H_

#include <queue>
#include <vector>
#include "raptor_data.h"
#include "raptor_decoder.h"

class RaptorDecoder
{
public:
  RaptorDecoder() {}
  RaptorDecoder(unsigned int K, unsigned int N, unsigned int lossNum):m_K(K), m_N(N), m_lossNum(lossNum) {}

  void set_parameters(unsigned int K, unsigned int N, unsigned int lossNum)
  {
    m_K = K;
    m_N = N;
    m_lossNum = lossNum;
  }

  void set_ESI(unsigned int ESI)
  {
    ESI_vector.push_back(ESI);
  }
  
  void set_data(std::vector<unsigned char> &encoded_data);
  void produce_data(int N, int datalen);
  void decode();
  std::vector<unsigned char> get_decodedSym();
  bool is_empty();

  bool operator==(const RaptorDecoder& other) {return false;}
  bool operator!=(const RaptorDecoder& other) {return true;}
private:
  unsigned int m_K;
  unsigned int m_N;
  unsigned int m_lossNum;
  
  std::vector<unsigned int> ESI_vector;
  CDecoder *decoder;
  std::queue<CData> encodedSym;
  std::queue<CData> recoveredSym;

};

#endif