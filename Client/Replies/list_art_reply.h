#ifndef LIST_ART_REPLY_H
#define LIST_ART_REPLY_H


#include "Reply.h"
#include <vector>
#include <string>

using byte = char;

class list_art_reply : public Reply {
public:
	list_art_reply(const Connection& conn);
	virtual string print() override{
		return ans;
	}
private:
	string ans = "";
};

#endif
