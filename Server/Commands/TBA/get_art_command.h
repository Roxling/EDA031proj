#ifndef GET_ART_COMMAND_H
#define GET_ART_COMMAND_H


#include "Command.h"

class get_art_command : public Command {
public:
	virtual string exec(std::string& args) override{
	return "0";
	};
};

#endif
