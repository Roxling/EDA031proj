#ifndef LIST_NG_COMMAND_H
#define LIST_NG_COMMAND_H

#include "Command.h"

class list_ng_command : public Command {
public:
	list_ng_command(shared_ptr<Database> db2, shared_ptr<Connection> c);

	virtual void exec() override;
};

#endif
