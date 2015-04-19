%module raptor_decoder

%include <std_vector.i>
%include <stl.i>
#include <sting.i>
%include <std_queue.i>

%{
#include <queue>
#include <vector>
#include "raptor_types.h"
#include "raptor_configure.h"
#include "raptor_data.h"
#include "raptor_defines.h"
#include "raptor_tables.h"
#include "raptor_triple.h"
#include "raptor_xorPos.h"
#include "raptor_decoder.h"
#include "raptor_decoder_api.h"
%}

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
	
	bool operator==(const RaptorDecoder& other) { return false;}
	bool operator!=(const RaptorDecoder& other) { return true;}

private:
	unsigned int m_K;
	unsigned int m_N;
	unsigned int m_lossNum;
	
	std::vector<unsigned int> ESI_vector;
	CDecoder *decoder;
	std::queue<CData> encodedSym;
	std::queue<CData> recoveredSym;

};

namespace std{
%template(vectoruc) vector<unsigned char>;
%template(queueofCData) queue<CData>; 
}



