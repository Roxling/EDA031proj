#ifndef CREATE_ART_COMMAND_H
#define CREATE_ART_COMMAND_H


#include "Command.h"

class create_art_command : public Command {
public:
	create_art_command(string aut, string tit, string txt){
	authour = aut; 
	title = tit; 
	text = txt;
	}

	virtual string exec() override{
	shared_ptr<Article> art(new Article(author,title,text));
		try{
			db->addArticle(args,art);
			return protocol.ANS_CREATE_ART + " " +protocol.ANS_ACK + " " + protocol.ANS_END;	
		}
		catch(connectionclosedexception e){
		 return protocol.ANS_CREATE_ART + " " +protocol.ANS_NAK + " " + protocol.ERR_NG_DOES_NOT_EXIST + " " + protocol.ANS_END;	
		}
	};
private:
	string author, title, text;
};

#endif
