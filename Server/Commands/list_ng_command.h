#ifndef LIST_NG_COMMAND_H
#define LIST_NG_COMMAND_H

#include "Command.h"

class list_ng_command : public Command {
public:
	virtual string exec() override{
	args += 'a'; //warning suppression

	return "listng \n" + db->listNewsGroups();
	};
};

#endif
