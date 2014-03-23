#ifndef LIST_ART_COMMAND_H
#define LIST_ART_COMMAND_H

#include "Command.h"

class list_art_command : public Command {
public:
	list_art_command(string ID){
		ngID = ID;
	}
	virtual string exec() override{
	
		try{	
			db->listArticles(ngID);
			return p.ANS_LIST_ART + " " + p.ANS_ACK + " " + p.ANS_END;
		}
		catch{
			return p.ANS_LIST_ART + " " + p.ANS_NAK + " " + p.ERR_NG_DOES_NOT_EXISTS + " " + p.ANS_END; //Two cases here aswell...
		}	
	};
private:
	string ngID;
	
};

#endif
