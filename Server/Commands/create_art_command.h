#ifndef CREATE_ART_COMMAND_H
#define CREATE_ART_COMMAND_H


#include "Command.h"

class create_art_command : public Command {
public:
	virtual string exec() override{
	return "listng \n" + db->listNewsGroups();
	};
};

#endif
