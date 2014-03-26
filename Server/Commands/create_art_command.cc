#include "create_art_command.h"
#include "Command.h"

create_art_command::create_art_command(shared_ptr<Database>& db2, shared_ptr<Connection>& c) : Command(db2,c){
	if(conn->read() != protocol.COM_END) protocolBroken();
}

void create_art_command::exec(){
	vector<pair<string, int>> ing = db->listNewsGroups();
	conn->write(protocol.ANS_LIST_NG);
	addParNumber(ing.size(), conn); //wrrite number of newsgroups
	for(pair<string,int> pa : ing){
		addParNumber(pa.second, conn); //write ID
		addParString(pa.first,conn); //write name
	}
	conn->write(protocol.ANS_END);
}
