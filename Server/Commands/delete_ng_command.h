#ifndef DELETE_NG_COMMAND_H
#define DELETE_NG_COMMAND_H


#include "Command.h"

class delete_ng_command : public Command {
public:
	delete_ng_command(shared_ptr<Database> db2,shared_ptr<Connection> conn);
	virtual void exec() override;
private:
	string ngID;
};

#endif
