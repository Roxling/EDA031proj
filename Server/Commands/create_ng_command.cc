#include "create_ng_command.h"

create_ng_command::create_ng_command(shared_ptr<Database>& db2,shared_ptr<Connection>& c): Command(db2,c){
		//check parse
		if(conn->read() == protocol.PAR_STRING){
			int n = readNumber(*conn);
			for(int i = 0; i< n; ++i){
				ngname += conn->read();
			}
		}else{
			protocolBroken();
		}
		if(conn->read() != protocol.COM_END){
			protocolBroken();
		}
	}

void create_ng_command::exec(){
	shared_ptr<NewsGroup> ng(new NewsGroup(ngname));
	conn->write(protocol.ANS_CREATE_NG);
	if(db->addNewsGroup(ng)){
		conn->write(protocol.ANS_ACK);
	}else{
		conn->write(protocol.ANS_NAK);
		conn->write(protocol.ERR_NG_ALREADY_EXISTS);
	}
		conn->write(protocol.ANS_END);
}

