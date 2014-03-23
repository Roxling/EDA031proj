#ifndef CREATE_NG_COMMAND_H
#define CREATE_NG_COMMAND_H

#include "Command.h"

class create_ng_command : public Command {
public:
	virtual string exec(std::string& args, unique_ptr<Database>& db) override{
	shared_ptr<NewsGroup> ng(new NewsGroup(getArgs(args)));
	db->addNewsGroup(ng);
	return "added newsgroup " + getArgs(args); 
	};
};

#endif
