#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "../DB/Database.h"

using namespace std;

class Command{
public:
	Command(){}
	virtual string exec() = 0;
	
	string getArgs(string cmdLine){
		string args;
		/*
		for(string::iterator it = (cmdLine.begin() +=2) ; it != cmdLine.end(); ++it) {
			args+= *it;	
		}
		*/
		return args;
	};
	
private:
	string args;
	shared_ptr<Database> db;
};
#endif

