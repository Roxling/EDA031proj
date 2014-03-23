#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "../DB/Database.h"
#include "../../protocol.h"
#include <vector>

using namespace std;
using byte = char;

class Command{
public:
	Command(){};
	virtual vector<byte>& exec() = 0;
	
protected:
	vector<byte> ret;
	Protocol p;
	shared_ptr<Database> db;	
};
#endif

