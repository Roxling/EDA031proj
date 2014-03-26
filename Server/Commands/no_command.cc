#include "no_command.h"
#include "Command.h"

no_command::no_command(shared_ptr<Database>& db2, shared_ptr<Connection>& c) : Command(db2,c){}

void no_command::exec(){
	protocolBroken();
}
