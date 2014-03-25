#ifndef GET_ART_REPLY_H
#define GET_ART_REPLY_H


#include "Reply.h"
#include <vector>
#include <string>

using byte = char;

class get_art_reply : public Reply {
public:
	get_art_reply(const Connection& conn);
	virtual string print() override{
		return ans;
	}
private:
	string ans = "";
};

#endif
