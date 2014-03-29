#include "CommandFactory.h"


#include "create_ng_command.h"

#include "delete_ng_command.h"

#include "list_art_command.h"

#include "create_art_command.h"
#include "delete_art_command.h"
#include "get_art_command.h"


#include "list_ng_command.h"
#include "no_command.h"
#include "../../connection.h"

#include <iostream>

using namespace std;

unique_ptr<Command> CommandFactory::createcommand(shared_ptr<Connection>& conn){
		switch (conn->read() - 0){
		case p.COM_LIST_NG:
			return unique_ptr<Command>(new list_ng_command(database, conn));
		case p.COM_CREATE_NG:
			return unique_ptr<Command>(new create_ng_command(database,conn));
		case p.COM_DELETE_NG:
			return unique_ptr<Command>(new delete_ng_command(database,conn));
		case p.COM_LIST_ART:
			return unique_ptr<Command>(new list_art_command(database,conn));
		case p.COM_CREATE_ART:
			return unique_ptr<Command>(new create_art_command(database,conn));
		case p.COM_DELETE_ART:
			return unique_ptr<Command>(new delete_art_command(database,conn));
		case p.COM_GET_ART:
			return unique_ptr<Command>(new get_art_command(database,conn));
		default:
			return unique_ptr<Command>(new no_command(database,conn));
		}	
}

