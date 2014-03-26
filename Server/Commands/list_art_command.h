#ifndef LIST_ART_COMMAND_H
#define LIST_ART_COMMAND_H

#include "Command.h"
#include <vector>

class list_art_command : public Command {
public:
	list_art_command(shared_ptr<Database> db2,shared_ptr<Connection> conn){
		//PARSING! WEEEE!

		try{
		if(conn->read() != protocol.PAR_NUM) protocolBroken();
		int n = readNumber(*conn);
		ngID = to_string(n);
		if(conn->read() != protocol.COM_END) protocolBroken();
		}catch(...){
		std::cout << "Caught a nefarious exception in list_art!" << std::endl;
		protocolBroken();
		}
	}
	virtual void exec() override{
		try{
		vector<pair<string,int>> arts = db->listArticles(ngID);
		conn->write(protocol.ANS_LIST_ART);
		addParNumber(arts.size(),conn);
		for(pair<string,int> pa: arts){
			addParNumber(pa.second,conn);
			addParString(pa.first,conn);
		}
		conn->write(protocol.ANS_END);
		}catch(...){
			
		}	
	};
private:
	string ngID;
	
};

#endif
