#ifndef GET_ART_COMMAND_H
#define GET_ART_COMMAND_H


#include "Command.h"

class get_art_command : public Command {
public:
	virtual string exec() override{
	args += 'a'; //warning suppression
	return "listng \n" + db->listNewsGroups();
	};
};

#endif
