%module raptor_encoder

%include <std_vector.i>
%include <stl.i>
%include <std_string.i>
%include "std_queue.i"

%{
#include <queue>
#include <vector>
#include <string>
#include "raptor_types.h"
#include "raptor_configure.h"
#include "raptor_data.h"
#include "raptor_defines.h"
#include "raptor_tables.h"
#include "raptor_triple.h"
#include "raptor_xorPos.h"
#include "raptor_encoder.h"
#include "raptor_encoder_api.h"
%}

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
	std::vector<unsigned char> get_encodedSym();
	bool is_empty();
	int count_encodedSym();
	void stringToVector(const std::string &strData, std::vector<unsigned char> &vecData);

private:
	CEncoder *encoder;
	std::queue<CData> encodedSym;
};

namespace std{
%template(vectoruc) vector<unsigned char>;
}



