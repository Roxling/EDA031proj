#include "create_ng_command.h"

	create_ng_command::create_ng_command(shared_ptr<Database> db2,shared_ptr<Connection> c): Command(db2,c){	
			//check parse
			try{
				if(conn->read() != p.PAR_STRING) protocolBroken();
				int n = readNumber(*conn);
				for(int i = 0; i< n; ++i){
					ngID += conn->read();
				}
				if(conn->read() != p.COM_END) protocolBroken();
			}catch(...){
				protocolBroken();
			}
		}

	virtual void create_ng_command::exec(){
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
	
	}


#endif
