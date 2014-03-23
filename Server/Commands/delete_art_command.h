#ifndef DELETE_ART_COMMAND_H
#define DELETE_ART_COMMAND_H


#include "Command.h"

class delete_art_command : public Command {
public:
	virtual string exec() override{
	args += 'a'; //warning suppression
	return "listng \n" + db->listNewsGroups();
	};
};

#endif
