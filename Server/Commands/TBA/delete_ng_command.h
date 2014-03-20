#ifndef DELETE_NG_COMMAND_H
#define DELETE_NG_COMMAND_H


#include "Command.h"

class delete_ng_command : public Command {
public:
	virtual string exec(std::string& args, unique_ptr<Database> db) override{
	return "0";
	};
};

#endif
