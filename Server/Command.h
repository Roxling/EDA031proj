#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command{
public:
	virtual void exec(std::string& args){};
};

#endif

