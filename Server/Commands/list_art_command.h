#ifndef LIST_ART_COMMAND_H
#define LIST_ART_COMMAND_H

#include "Command.h"
#include <vector>

class list_art_command : public Command {
public:
	list_art_command(shared_ptr<Database>& db2,shared_ptr<Connection>& conn);
	virtual void exec() override;
private:
	string ngID;
	
};

#endif
