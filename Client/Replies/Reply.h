#ifndef REPLY_H
#define REPLY_H

#include <string>
#include <vector>
#include "../../protocol.h"

using namespace std;
using byte = char;
class Reply{
public:
	virtual string exec() = 0;
protected:
	int readNumber(vector<byte>& integer,unsigned int startpos) {
		if(integer.size() >= startpos+4){
			return (integer[startpos] << 24) | (integer[startpos+1] << 16) | (integer[startpos+2] << 8) | integer[startpos+3];
		}
		return -1;	
	}
	Protocol protocol;
};
#endif

