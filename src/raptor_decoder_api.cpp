#include <stdio.h>
#include <stdlib.h>
#include "raptor_decoder_api.h"

using std::vector;

#define random(x) (rand() % x)

void RaptorDecoder::set_data(std::vector<unsigned char> &encoded_data)
{
	size_t data_size = encoded_data.size();
	U8 *data_buf = new U8[data_size];
	for (size_t i = 0; i < data_size; ++i)
	{
		data_buf[i] = encoded_data[i];
	}
	
	CData data(data_buf, data_size);
	encodedSym.push(data);

	delete[] data_buf;
	data_buf = NULL;
}

void RaptorDecoder::produce_data(int N, int dataLen)
{
	const int DATA_LEN = 1024;
	U8 rndData[DATA_LEN];
	
	for (U32 i = 0; i < N; ++i)
	{
		for (U32 j = 0; j < dataLen; ++j)
		{
			rndData[j] = random(256);

#ifdef TEST_PURPOSE
			index++;
			printf("%6d", rndData[j]);
			if ((index % SHOW_NUMS) == 0)
			{
				printf("\n");
			}
#endif
		}
		
		CData data(rndData, dataLen);
	  encodedSym.push(data);
	}
	
	decoder = new CDecoder(m_K, m_N, m_lossNum, ESI_vector);
	recoveredSym = decoder->Decode(encodedSym);
}

void RaptorDecoder::decode()
{
	decoder = new CDecoder(m_K, m_N, m_lossNum, ESI_vector);
	recoveredSym = decoder->Decode(encodedSym);
}

vector<unsigned char> RaptorDecoder::get_decodedSym()
{
	CData data = recoveredSym.front();
	recoveredSym.pop();

	vector<U8> res;
	U8 *buf = data.GetData();
	int data_size = data.GetLen();
	for (U32 j = 0; j < data_size; ++j)
	{
		res.push_back(buf[j]);
	}

	return res;
}

bool RaptorDecoder::is_empty()
{
	return recoveredSym.empty();
}