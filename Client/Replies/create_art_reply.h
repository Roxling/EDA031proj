#ifndef CREATE_ART_REPLY_H
#define CREATE_ART_REPLY_H


#include "Reply.h"
#include <vector>
#include <string>

using byte = char;

class create_art_reply : public Reply {
public:
	create_art_reply(const Connection& conn);
	virtual string print() override{
		return ans;
	}
private:
	string ans = "";
};

#endif
