#ifndef NO_REPLY_H
#define NO_REPLY_H


#include "Reply.h"

class no_reply : public Reply {
public:
	virtual string exec() override{
		return "No readable reply from server, protocol broken.";
	}
};

#endif
