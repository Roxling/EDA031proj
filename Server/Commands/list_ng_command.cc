#include "list_ng_command.h"
#include "Command.h"

list_ng_command::list_ng_command(shared_ptr<Database>& db2, shared_ptr<Connection>& c) : Command(db2,c){
	if(conn->read() != protocol.COM_END) protocolBroken();
}

void list_ng_command::exec(){
	vector<pair<string, int>> ing = db->listNewsGroups();
	conn->write(protocol.ANS_LIST_NG);
	addParNumber(ing.size(), conn); //write number of newsgroups
	for(auto pa : ing){
		addParNumber(pa.second, conn); //write ID
		addParString(pa.first,conn); //write name
	}
	conn->write(protocol.ANS_END);
}
