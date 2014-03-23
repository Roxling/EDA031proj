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
			return p.ANS_CREATE_ART + " " +p.ANS_ACK + " " + p.ANS_END;	
		}
		catch(connectionclosedexception e){
		 return p.ANS_CREATE_ART + " " +p.ANS_NAK + " " + p.ERR_NG_DOES_NOT_EXIST + " " + p.ANS_END;	
		}
	};
private:
	string author, title, text;
};

#endif
