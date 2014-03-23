#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Command.h"
#include <string>
#include <memory>
#include "../../protocol.h"

using namespace std;
using byte = char;
class CommandFactory{
public:
	std::unique_ptr<Command> createcommand(char cmd);
private:
	Protocol p;

};


#endif
