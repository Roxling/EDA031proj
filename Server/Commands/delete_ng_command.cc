#include "delete_ng_command.h"
#include "Command.h"

delete_ng_command::delete_ng_command(shared_ptr<Database> db2, shared_ptr<Connection> c) : Command(db2,c){
	try{
		if(conn->read() != protocol.PAR_NUM)protocolBroken();
		int n  = conn->read();
		ngID = to_string(n);
		if(conn->read() != protocol.COM_END)protocolBroken();
	}catch(...){
		std::cout << "Caught a villanous exception in delete_NG!" << std::endl;
		protocolBroken();
	}
}

void delete_ng_command::exec(){
	try{
	   db->removeNewsGroup(ngID);
	}catch(...){
	   protocolBroken();

	   conn->write(protocol.ANS_DELETE_NG);
	   conn->write(protocol.ANS_NAK);
	   conn->write(protocol.ERR_NG_DOES_NOT_EXIST);
	   conn->write(protocol.ANS_END);
	}
	//deal with errors
	conn->write(protocol.ANS_DELETE_NG);
	conn->write(protocol.ANS_ACK);
	conn->write(protocol.ANS_END);
}
