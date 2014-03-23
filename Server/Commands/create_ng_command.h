#ifndef CREATE_NG_COMMAND_H
#define CREATE_NG_COMMAND_H

#include "Command.h"
#include "../../connectionclosedexception.h"

class create_ng_command : public Command {
public:
	create_ng_command(shared_ptr<Database> db2,string ID) : ngID(ID){
		db = db2;		
		}

	virtual vector<byte>& exec() override{
		shared_ptr<NewsGroup> ng(new NewsGroup(ngID));
		
		try{	
			db->addNewsGroup(ng);
			ret.push_back(p.ANS_CREATE_NG);
			ret.push_back(' ');
			ret.push_back(p.ANS_ACK);
			ret.push_back(' ');
			ret.push_back(p.ANS_END);
			return ret;
		}
		catch(ConnectionClosedException e){
			ret.push_back(p.ANS_CREATE_NG);
			ret.push_back(' ');
			ret.push_back(p.ANS_NAK);
			ret.push_back(' ');
			ret.push_back(p.ERR_NG_ALREADY_EXISTS);
			ret.push_back(' ');
			ret.push_back(p.ANS_END);
			return ret; 
		}
	
	};
private:
	string ngID;

};

#endif
