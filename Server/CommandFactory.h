#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Command.h"
#include <string>
#include "protocol.h"

using namespace std;
using byte = char;
class CommandFactory{
public:
	Command createcommand(byte& cmd);
private: struct Protocol p;

};


#endif
