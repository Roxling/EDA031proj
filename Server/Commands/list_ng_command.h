#ifndef LIST_NG_COMMAND_H
#define LIST_NG_COMMAND_H

#include "Command.h"

class list_ng_command : public Command {
public:
	virtual string exec(std::string& args, unique_ptr<Database>& db) override{
	//args += 'a'; //warning suppression
	args = getArgs(args);
	return "listng \n" + "getArgs() = " + args; //+ db->listNewsGroups();
	};
};

#endif
