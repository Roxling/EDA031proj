#ifndef NO_COMMAND_H
#define NO_COMMAND_H


#include "Command.h"

class no_command : public Command {
public:
	virtual string exec(std::string& args) override{
		args += 'a'; //warning suppression
		return "Faulty command!";
		//TODO Terminate client
	};
};

#endif
