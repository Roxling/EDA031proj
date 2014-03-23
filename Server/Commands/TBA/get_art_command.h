#ifndef GET_ART_COMMAND_H
#define GET_ART_COMMAND_H


#include "Command.h"

class get_art_command : public Command {
public:
	get_art_command(string aID, string ID){
		ngID =  nID;
		artID = aID;	
	}
	virtual string exec() override{

		try{	
			db->(ng);
			return p.ANS_GET_NG + " " + p.ANS_ACK + " " + p.ANS_END;
		}
		catch{
			return p.ANS_GET_NG + " " + p.ANS_NAK + " " + p.ERR_NG_DOES_NOT_EXISTS + " " + p.ANS_END; //Two cases here aswell...
		}
	
	};

private:
	string ngId;
	string artID;
};

#endif
