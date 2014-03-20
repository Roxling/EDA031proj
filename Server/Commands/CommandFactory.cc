#include "CommandFactory.h"

/*
#include "create_ng_command.h"
#include "delete_ng_command.h"

#include "list_art_command.h"
#include "create_art_command.h"
#include "delete_art_command.h"
#include "get_art_command.h"

*/

#include "list_ng_command.h"
#include "no_command.h"

#include <iostream>

using namespace std;
unique_ptr<Command> CommandFactory::createcommand(char cmd){
		
		switch (cmd-'0')
		{
		case p.COM_LIST_NG:  {//list newgroup
			unique_ptr<Command> c(new list_ng_command());
			return  c;
		    	break; }
		/*
		case p.COM_CREATE_NG:{
			unique_ptr<Command> c(new create_ng_command());
			return  c;
		    	break;}
		case p.COM_DELETE_NG:{
			unique_ptr<Command> c(new delete_ng_command());
			return  c;
		    	break;}
		case p.COM_LIST_ART:{
			unique_ptr<Command> c(new list_art_command());
			return  c;
			break;}
		case p.COM_CREATE_ART:{
			unique_ptr<Command> c(new create_art_command());
			return  c;
			break;}
		case p.COM_DELETE_ART:{
			unique_ptr<Command> c(new delete_art_command());
			return  c;	
			break;}
		case p.COM_GET_ART:{
			unique_ptr<Command> c(new get_art_command());
			return  c;	
			break;}
			*/
		default:
			unique_ptr<Command> c(new no_command());
			return  c;
 		    	break;
		}	
		
		
}
