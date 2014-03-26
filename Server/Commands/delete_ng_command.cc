#include "delete_ng_command.h"
#include "Command.h"

delete_ng_command::delete_ng_command(shared_ptr<Database>& db2, shared_ptr<Connection>& c) : Command(db2,c){
	if(conn->read() == protocol.PAR_NUM){
		ngID = to_string(readNumber(*conn));
	}else{
		protocolBroken();
	}
	if(conn->read() != protocol.COM_END){
		protocolBroken();
	}
}

void delete_ng_command::exec(){
	conn->write(protocol.ANS_DELETE_NG);
	if(db->removeNewsGroup(ngID)){
		conn->write(protocol.ANS_ACK);
	}else{
		conn->write(protocol.ANS_NAK);
		conn->write(protocol.ERR_NG_DOES_NOT_EXIST);
	}
	conn->write(protocol.ANS_END);
}
