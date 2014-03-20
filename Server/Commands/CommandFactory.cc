#include "Command.h"
#include "CommandFactory.h"
#include <string>

#include "create_ng_command.h"
#include "delete_ng_command.h"
#include "list_ng_command.h"
#include "list_art_command.h"
#include "create_art_command.h"
#include "delete_art_command.h"
#include "get_art_command.h"
#include "no_command.h"

#include <iostream>

Command CommandFactory::createcommand(byte& cmd){
	
		switch (cmd)
		{
		case p.COM_LIST_NG: //list newgroup
			return list_ng_command();
		    	break;
		case p.COM_CREATE_NG:
			return create_ng_command();
		    	break;
		case p.COM_DELETE_NG:
			return delete_ng_command();
		    	break;
		case p.COM_LIST_ART:
			return list_art_command();
			break;
		case p.COM_CREATE_ART:
			return create_art_command();
			break;
		case p.COM_DELETE_ART:
			return delete_art_command();
			break;
		case p.COM_GET_ART:
			return get_art_command();	
			break;
		default: return no_command();
		    break;
		}	
		
		return no_command();
		
}
