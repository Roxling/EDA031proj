#ifndef LIST_NG_REPLY_H
#define LIST_NG_REPLY_H


#include "Reply.h"
#include <vector>
#include <string>

using byte = char;

class list_ng_reply : public Reply {
public:
	list_ng_reply(const Connection& conn);
	virtual string print() override{
		return ans;
	}
private:
	string ans = "";
};

#endif
