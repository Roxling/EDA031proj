#ifndef LIST_NG_COMMAND_H
#define LIST_NG_COMMAND_H

#include "Command.h"

class list_ng_command : public Command {
public:
	list_ng_command(shared_ptr<Database> db2, shared_ptr<Connection> c){
	db = db2;
	conn = c;
	//check parsing on in-command
	if(conn->read() != p.COM_END) throwProtocolException();
	};

	virtual vector<byte>& exec() override{
		 vector<pair<string, int>> ing = db->listNewsGroups();
		conn->write(p.ANS_LIST_NG);
		conn->write(' ');
		addParNumber(ing.size(), conn); //wrrite number of newsgroups
		conn->write(' ');
		for(pair<string,int> pa : ing){
			addParNumber(pa.second, conn); //write ID
			conn->write(' ');
			addParString(pa.first,conn); //write name
		}

		conn->write(p.ANS_END);
		return ret;
	};
};

#endif
