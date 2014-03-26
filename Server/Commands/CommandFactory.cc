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
			cout << "Creating List NG Command" << endl;
			return unique_ptr<Command>(new list_ng_command(database, conn));
		case p.COM_CREATE_NG:
			cout << "Creating create NG Command" << endl;
			return unique_ptr<Command>(new create_ng_command(database,conn));
		case p.COM_DELETE_NG:
			cout << "Creating delete NG Command" << endl;
			return unique_ptr<Command>(new delete_ng_command(database,conn));
		case p.COM_LIST_ART:
			cout << "Creating list ART Command" << endl;
			return unique_ptr<Command>(new list_art_command(database,conn));
		/*
		case p.COM_CREATE_ART:{
			unique_ptr<Command> c(new create_art_command(database));
			return  c;
			break;}
		case p.COM_DELETE_ART:{
			unique_ptr<Command> c(new delete_art_command(database));
			return  c;	
			break;}
		case p.COM_GET_ART:{
			unique_ptr<Command> c(new get_art_command(database));
			return  c;	
			break;} */
		default:
			cout << "Creating NO_Command" << endl;
			return unique_ptr<Command>(new no_command(database,conn));
		}	
}

