#ifndef CREATE_ART_COMMAND_H
#define CREATE_ART_COMMAND_H

#include "Command.h"

class create_art_command : public Command {
public:
	create_art_command(shared_ptr<Database>& db2, shared_ptr<Connection>& c);

	virtual void exec() override;

private:
	int artID;
	string title;
	string author;
	string text;
};

#endif
