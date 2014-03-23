#ifndef DELETE_NG_COMMAND_H
#define DELETE_NG_COMMAND_H


#include "Command.h"

class delete_ng_command : public Command {
public:
	virtual string exec() override{
	db->removeNewsGroup(getArgs(args));
	return "removed" + getArgs(args);
	};
};

#endif
