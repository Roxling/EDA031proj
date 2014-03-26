#include "get_art_command.h"
#include "Command.h"

get_art_command::get_art_command(shared_ptr<Database>& db2, shared_ptr<Connection>& c) : Command(db2,c){
	if(conn->read() == protocol.PAR_NUM){
		ngID = to_string(readNumber(*conn));
		if(conn->read() == protocol.PAR_NUM){
			artID = to_string(readNumber(*conn));
		}else{
			protocolBroken();
		}
	}else{
		protocolBroken();
	}
	if(conn->read() != protocol.COM_END){
		protocolBroken();
	}
}

void get_art_command::exec(){
	conn->write(protocol.ANS_GET_ART);
	if(db->containsArticle(ngID,artID)){
		conn->write(protocol.ANS_ACK);
		auto art = db->readArticle(ngID,artID);
		for(string& s : art){
			addParString(s,conn);
		}

	}else{
		conn->write(protocol.ANS_NAK);
		if(db->containsNewsGroup(ngID)){
			conn->write(protocol.ERR_ART_DOES_NOT_EXIST);
		}else{
			conn->write(protocol.ERR_NG_DOES_NOT_EXIST);
		}
	}
	conn->write(protocol.ANS_END);
}
