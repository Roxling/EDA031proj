#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command{
public:
	Command(){}
	virtual std::string exec(std::string& args,db) = 0;
};
#endif

