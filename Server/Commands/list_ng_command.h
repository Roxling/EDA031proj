#ifndef LIST_NG_COMMAND_H
#define LIST_NG_COMMAND_H

#include "Command.h"

class list_ng_command : public Command {
public:
	list_ng_command(shared_ptr<Database> db2){
	db = db2;
	};

	virtual vector<byte>& exec() override{
		 db->listNewsGroups();

		//Do magic
	
		ret.push_back(p.ANS_LIST_NG);
		ret.push_back(' ');
		ret.push_back(p.PAR_NUM);
		ret.push_back(' ');
		ret.push_back(p.ANS_ACK);
		return ret;
	};
};

#endif
