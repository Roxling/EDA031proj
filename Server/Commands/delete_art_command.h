#ifndef DELETE_ART_COMMAND_H
#define DELETE_ART_COMMAND_H

#include "Command.h"

class delete_art_command : public Command {
public:
	delete_art_command(shared_ptr<Database> db2, shared_ptr<Connection> c);

	virtual void exec() override;
};

#endif
