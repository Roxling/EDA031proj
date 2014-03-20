#ifndef LIST_ART_COMMAND_H
#define LIST_ART_COMMAND_H


#include "Command.h"

class list_art_command : public Command {
public:
	virtual string exec(std::string& args) override{
	return "0";
	};
};

#endif
