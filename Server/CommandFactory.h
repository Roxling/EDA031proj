#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Command.h"
#include <string>
#include "protocol.h"

using namespace std;

class CommandFactory{

public:
	Command createcommand(string cmd);


};

CommandFactory::createcommand(string cmd){
		Command c;
		return c;
}



#endif
