#include "create_art_command.h"
#include "Command.h"

create_art_command::create_art_command(shared_ptr<Database>& db2, shared_ptr<Connection>& c) : Command(db2,c){
	
	if(conn->read() != protocol.PAR_NUM){
		protocolBroken();
	}
	artID = readNumber(*conn);
	if(conn->read() != protocol.PAR_STRING){
		protocolBroken();
	}
	title = readString(*conn);
	if(conn->read() != protocol.PAR_STRING){
		protocolBroken();
	}
	author = readString(*conn);
	if(conn->read() != protocol.PAR_STRING){
		protocolBroken();
	}
	text = readString(*conn);

	if(conn->read() != protocol.COM_END){
		protocolBroken();
	}
}

void create_art_command::exec(){

		conn->write(protocol.ANS_CREATE_ART);
		if(db->addArticle(artID,shared_ptr<Article>(new Article(author, title, text)))){
			conn->write(protocol.ANS_ACK);
		}else{
			conn->write(protocol.ANS_NAK);
			conn->write(protocol.ERR_NG_DOES_NOT_EXIST);
		}
			conn->write(protocol.ANS_END);

}
