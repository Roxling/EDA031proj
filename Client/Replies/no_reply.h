#ifndef NO_REPLY_H
#define NO_REPLY_H


#include "Reply.h"
#include <iostream>

class no_reply : public Reply {
public:
	no_reply(){}
	virtual string print() override{
		protocolBroken();
		return "";
	}
};

#endif
