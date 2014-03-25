#ifndef DELETE_NG_COMMAND_H
#define DELETE_NG_COMMAND_H


#include "Command.h"

class delete_ng_command : public Command {
public:
	delete_ng_command(shared_ptr<Database> db2,shared_ptr<Connection> conn){
		db = db2;
		//check parse	

		try{
			if(conn->read() != p.PAR_NUM)throwProtocolException();
			int n  = conn->read();
			ngID = to_string(n);
			if(conn->read() != p.COM_END)throwProtocolException();
		}catch(...){
			std::cout << "Caught a villanous exception in delete_NG!" << std::endl;
			throwProtocolException();
		}
		
	}
	virtual void exec() override{
		try{
		   db->removeNewsGroup(ngID);
		}catch(...){
		   throwProtocolException();
		  	
		   conn->write(p.ANS_DELETE_NG);
		   conn->write(p.ANS_NAK);
		   conn->write(p.ERR_NG_DOES_NOT_EXIST);
		   conn->write(p.ANS_END);
		}
		//deal with errors
		conn->write(p.ANS_DELETE_NG);
		conn->write(p.ANS_ACK);
		conn->write(p.ANS_END);
	
	};
private:
	string ngID;
};

#endif
