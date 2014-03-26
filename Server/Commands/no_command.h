#ifndef NO_COMMAND_H
#define NO_COMMAND_H

#include "Command.h"

class no_command : public Command {
public:
	no_command(shared_ptr<Database>& db2, shared_ptr<Connection>& c);
	virtual void exec() override;
};

#endif
