#ifndef CREATE_NG_COMMAND_H
#define CREATE_NG_COMMAND_H

#include "Command.h"
#include "../../connectionclosedexception.h"

class create_ng_command : public Command {
public:

	create_ng_command(shared_ptr<Database>& db2,shared_ptr<Connection>& conn);
	virtual void exec() override;
private:
	string ngname;

};

#endif
