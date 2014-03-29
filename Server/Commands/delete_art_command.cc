#include "delete_art_command.h"
#include "Command.h"

delete_art_command::delete_art_command(shared_ptr<Database>& db2, shared_ptr<Connection>& c) : Command(db2,c){
	if(conn->read() == protocol.PAR_NUM){
		ngid = readNumber(*conn);
		if(conn->read() == protocol.PAR_NUM){
			artid = readNumber(*conn);
		}else{
			protocolBroken();
		}
	}else{
		protocolBroken();
	}
	if(conn->read() != protocol.COM_END) protocolBroken();
}

void delete_art_command::exec(){
	conn->write(protocol.ANS_DELETE_ART);
	if(db->removeArticle(ngid,artid)){
		conn->write(protocol.ANS_ACK);
	}else{
		conn->write(protocol.ANS_NAK);
		if(db->containsNewsGroup(ngid)){
			conn->write(protocol.ERR_ART_DOES_NOT_EXIST);
		}else{
			conn->write(protocol.ERR_NG_DOES_NOT_EXIST);
		}
	}
	conn->write(protocol.ANS_END);
}
