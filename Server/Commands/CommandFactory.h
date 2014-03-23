#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Command.h"
#include <string>
#include <memory>
#include "../../protocol.h"
#include "../DB/Database.h"

using namespace std;
using byte = char;
class CommandFactory{
public:
	CommandFactory(Database& db): database(db){}
	std::unique_ptr<Command> createcommand(char cmd);
private:
	Protocol p;
	Database database;
};


#endif
