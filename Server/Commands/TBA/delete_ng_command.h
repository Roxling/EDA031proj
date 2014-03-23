#ifndef DELETE_NG_COMMAND_H
#define DELETE_NG_COMMAND_H


#include "Command.h"

class delete_ng_command : public Command {
public:
	delete_ng_command(string ID){
		ngID = ID;
	}
	virtual string exec() override{

		try{	
			db->removeNewsGroup(ID);
			return p.ANS_DELETE_NG + " " + p.ANS_ACK + " " + p.ANS_END;
		}
		catch{
			return p.ANS_DELETE_NG + " " + p.ANS_NAK + " " + p.ERR_NG_DOES_NOT_EXISTS + " " + p.ANS_END;
		}
	
	};
private:
	string ngID;
};

#endif
