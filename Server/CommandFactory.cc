#include "Command.h"
#include "CommandFactory.h"
#include <string>

Command CommandFactory::createcommand(string cmd){
		//substring(
		cmd += 'a'; //warning suppression
		string s;
		Command* c = new Command();
		return *c;
}
