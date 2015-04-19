#ifndef __RAPTOR_ENCODER_API_H_
#define __RAPTOR_ENCODER_API_H_

#include <queue>
#include <vector>
#include <string>
#include "raptor_data.h"
#include "raptor_encoder.h"

class RaptorEncoder
{
public:
	RaptorEncoder(int K, int lossNum, int overhead)
	{ 
		encoder = new CEncoder(K, lossNum, overhead);
	}

	~RaptorEncoder()
	{
		if (encoder != NULL)
		{
			delete encoder;
			encoder = NULL;
		}
	}

  void set_data(const std::string &raw_data);
	void get_data_access();
	std::vector<U8> get_encodedSym();
	bool is_empty();
	int count_encodedSym();
	void stringToVector(const std::string &strData, std::vector<unsigned char> &vecData);

private:

	CEncoder *encoder;
	std::queue<CData> encodedSym;
};

#endif

