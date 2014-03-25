#ifndef DELETE_NG_REPLY_H
#define DELETE_NG_REPLY_H


#include "Reply.h"
#include <vector>
#include <string>

using byte = char;

class delete_ng_reply : public Reply {
public:
	delete_ng_reply(const Connection& conn);
	virtual string print() override{
		return ans;
	}
private:
	string ans = "";
};

#endif
