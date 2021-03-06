#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Command.h"
#include <string>
#include <memory>
#include <vector>
#include "../../protocol.h"
#include "../DB/Database.h"
#include "../../connection.h"

using namespace std;
using byte = char;
class CommandFactory{
public:
	CommandFactory(shared_ptr<Database>& db): database(db){}
	std::unique_ptr<Command> createcommand(shared_ptr<Connection>&);
private:
	Protocol p;
	shared_ptr<Database> database;
};


#endif
