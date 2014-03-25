#include "CommandFactory.h"


#include "create_ng_command.h"
/*
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

unique_ptr<Command> CommandFactory::createcommand(vector<byte> cmd){

		cout << "command: " << cmd[0]-0 << endl;
		switch (cmd[0]-0)
		{
		case p.COM_LIST_NG:  {//list newgroup
			cout << "Creating List NG Command" << endl;
			unique_ptr<Command> c(new list_ng_command(database));
			cout << "returning NG command" << endl;			
			return  c;
		    	break; }
		
		case p.COM_CREATE_NG:{
			string s;
			
			for(int i = 0; cmd[i] != p.COM_END; ++i){
			//Parse!
			s = cmd[4];
			int length = stoi(s);

			for( int j = 6; j <= 6+ length ; ++j)
			  s += cmd[j];
			}
			cout << "parameter: " <<  s << endl;

			unique_ptr<Command> c(new create_ng_command(database,s));
			return  c;
		    	break;}
		/*
		case p.COM_DELETE_NG:{
			unique_ptr<Command> c(new delete_ng_command(database));
			return  c;
		    	break;}
		case p.COM_LIST_ART:{
			unique_ptr<Command> c(new list_art_command(database));
			return  c;
			break;}
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
			unique_ptr<Command> c(new no_command());
			return  c;
 		    	break;
		}	
		
		
}
