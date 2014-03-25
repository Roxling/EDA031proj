#ifndef CREATE_NG_REPLY_H
#define CREATE_NG_REPLY_H


#include "Reply.h"
#include <vector>
#include <string>

using byte = char;

class create_ng_reply : public Reply {
public:
	create_ng_reply(const Connection& conn);
	virtual string print() override{
		return ans;
	}
private:
	string ans = "";
};

#endif
