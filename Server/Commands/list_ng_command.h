#ifndef LIST_NG_COMMAND_H
#define LIST_NG_COMMAND_H


#include "Command.h"
#include "Database.h"

class list_ng_command : public Command {
public:
	virtual string exec(std::string& args) override{
	args += 'a'; //warning suppression
	return "listng";
	//return myDatabase.listNewsGroups();
	};
};

#endif
