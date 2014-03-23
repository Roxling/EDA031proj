#ifndef CREATE_NG_COMMAND_H
#define CREATE_NG_COMMAND_H

#include "Command.h"

class create_ng_command : public Command {
public:
	virtual string exec() override{
	shared_ptr<NewsGroup> ng(new NewsGroup(getArgs(args)));
	db->addNewsGroup(ng);
	return "added newsgroup " 
	};
};

#endif
