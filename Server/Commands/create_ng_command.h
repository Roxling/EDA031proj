#ifndef CREATE_NG_COMMAND_H
#define CREATE_NG_COMMAND_H

#include "Command.h"
#include "../../connectionclosedexception.h"

class create_ng_command : public Command {
public:
	create_ng_command(shared_ptr<Database> db2,shared_ptr<Connection> conn){
			db = db2;	
			//check parse
			try{
				if(conn->read() != p.PAR_STRING) throwProtocolException();
				int n = readNumber(*conn);
				for(int i = 0; i< n; ++i){
					ngID += conn->read();
				}
				if(conn->read() != p.COM_END) throwProtocolException();
			}catch(...){
				throwProtocolException();
			}
		}

	virtual void exec() override{
		shared_ptr<NewsGroup> ng(new NewsGroup(ngID));
		
		try{	
			db->addNewsGroup(ng);
			conn->write(p.ANS_CREATE_NG);
			conn->write(p.ANS_ACK);
			conn->write(p.ANS_END);
		}
		catch(...){
			conn->write(p.ANS_CREATE_NG);
			conn->write(p.ANS_NAK);
			conn->write(p.ERR_NG_ALREADY_EXISTS);
			conn->write(p.ANS_END); 
		}
	
	};
private:
	string ngID;

};

#endif
