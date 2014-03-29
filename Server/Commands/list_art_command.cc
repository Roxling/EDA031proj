#include "list_art_command.h"
#include "Command.h"

list_art_command::list_art_command(shared_ptr<Database>& db2, shared_ptr<Connection>& c) : Command(db2,c){
	if(conn->read() == protocol.PAR_NUM){
		ngID = readNumber(*conn);
	}else{
		protocolBroken();
	}
	if(conn->read() != protocol.COM_END){
		protocolBroken();
	}
}

void list_art_command::exec(){
	conn->write(protocol.ANS_LIST_ART);
	if(db->containsNewsGroup(ngID)){
		conn->write(protocol.ANS_ACK);
		auto arts = db->listArticles(ngID);
		addParNumber(arts.size(),conn);
		for(auto art : arts){
			addParNumber(art.second,conn);
			addParString(art.first,conn);
		}
	}else{
		conn->write(protocol.ANS_NAK);
		conn->write(protocol.ERR_NG_DOES_NOT_EXIST);
	}
	conn->write(protocol.ANS_END);
}
