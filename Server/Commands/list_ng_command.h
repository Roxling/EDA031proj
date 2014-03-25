#ifndef LIST_NG_COMMAND_H
#define LIST_NG_COMMAND_H

#include "Command.h"
#include <pair>

class list_ng_command : public Command {
public:
	list_ng_command(shared_ptr<Database> db2){
	db = db2;
	};

	virtual vector<byte>& exec() override{
		 vector<pair<string, int>> ing = db->listNewsGroups();
		

		ret.push_back(p.ANS_LIST_NG);
		ret.push_back(' ');
		ret.push_back(p.PAR_NUM);  //FIX
		ret.push_back(' ');
		ret.push_back(ing.size());
		ret.push_back(' ');

		//Do magic
		for(pair pa : ing){
			ret.push_back(p.PAR_NUM);
			ret.push_back(' ');
			ret.push_back(pa.second); //FIX
			ret.push_back(' ');
			ret.push_back(p.PAR_STRING);
			ret.push_back(p.first.size); //FIX!! =O
			for(char c : p.first){			
				ret.push_back(c);
			}
			
		}


		ret.push_back(p.ANS_END);
		return ret;
	};
};

#endif
