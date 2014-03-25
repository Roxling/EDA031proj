#ifndef DELETE_ART_REPLY_H
#define DELETE_ART_REPLY_H


#include "Reply.h"
#include <vector>
#include <string>

using byte = char;

class delete_art_reply : public Reply {
public:
	delete_art_reply(const Connection& conn);
	virtual string print() override{
		return ans;
	}
private:
	string ans = "";
};

#endif
