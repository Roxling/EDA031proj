#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "../DB/Database.h"

class Command{
public:
	Command(){}
	virtual std::string exec(std::string& args, unique_ptr<Database>& db) = 0;
};
#endif

