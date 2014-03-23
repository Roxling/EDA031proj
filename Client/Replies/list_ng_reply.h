#ifndef LIST_NG_REPLY_H
#define LIST_NG_REPLY_H


#include "Reply.h"
#include <vector>
#include <string>

using byte = char;

class list_ng_reply : public Reply {
public:
	list_ng_reply(vector<byte>& c);
	virtual string exec() override{
		return ans;
	}
private:
	vector<byte>& comm;
	string ans;
	unsigned int minsize = 7;
};

#endif
