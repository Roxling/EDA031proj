#ifndef GET_ART_COMMAND_H
#define GET_ART_COMMAND_H

#include "Command.h"
#include <string>

class get_art_command : public Command {
public:
	get_art_command(shared_ptr<Database>& db2, shared_ptr<Connection>& c);

	virtual void exec() override;
private:
	string ngID;
	string artID;
};

#endif
