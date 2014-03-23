#ifndef DELETE_ART_COMMAND_H
#define DELETE_ART_COMMAND_H


#include "Command.h"

class delete_art_command : public Command {
public:
	delete_art_command(string ngID,string artID){
		newsgroupID = ngID;
		articleID = artID;
	};

	virtual string exec() override{
	
		try{	
			db->removeArticle(newsgroupID,articleID);
			return p.ANS_DELETE_ART + " " + p.ANS_ACK + " " + p.ANS_END;
		}
		catch{
			return p.ANS_DELETE_ART + " " + p.ANS_NAK + " " + p.ERR_NG_ALREADY_EXISTS + " " + p.ANS_END; //Has two possiblee exceptions...!
		}
	
	};


private:
	string newsgroupID;
	string articleID;
};

#endif
