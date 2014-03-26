#ifndef NO_COMMAND_H
#define NO_COMMAND_H


#include "Command.h"

class no_command : public Command {
public:
	virtual void exec() override{
		protocolBroken();
	}
};

#endif
