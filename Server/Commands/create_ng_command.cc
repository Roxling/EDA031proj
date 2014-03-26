#include "create_ng_command.h"

	create_ng_command::create_ng_command(shared_ptr<Database> db2,shared_ptr<Connection> c): Command(db2,c){	
			//check parse
			try{
				if(conn->read() != protocol.PAR_STRING) protocolBroken();
				int n = readNumber(*conn);
				for(int i = 0; i< n; ++i){
					ngID += conn->read();
				}
				if(conn->read() != protocol.COM_END) protocolBroken();
			}catch(...){
				protocolBroken();
			}
		}

	virtual void create_ng_command::exec(){
		shared_ptr<NewsGroup> ng(new NewsGroup(ngID));
		
		try{	
			db->addNewsGroup(ng);
			conn->write(protocol.ANS_CREATE_NG);
			conn->write(protocol.ANS_ACK);
			conn->write(protocol.ANS_END);
		}
		catch(...){
			conn->write(protocol.ANS_CREATE_NG);
			conn->write(protocol.ANS_NAK);
			conn->write(protocol.ERR_NG_ALREADY_EXISTS);
			conn->write(protocol.ANS_END);
		}
	
	}


#endif
