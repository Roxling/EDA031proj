#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "../DB/Database.h"
#include "../../protocol.h"
#include "../../connection.h"
#include "../../protocolbrokenexception.h"
#include <iostream>

using namespace std;
using byte = char;

class Command{
public:
	Command(shared_ptr<Database> db2, shared_ptr<Connection> c);
	virtual void exec() = 0;
	
protected:
	shared_ptr<Connection> conn;
	shared_ptr<Database> db;
	Protocol protocol;

	void addParString(string s, shared_ptr<Connection> conn);

	void addParNumber(int i, shared_ptr<Connection> conn);

	void writeNumber(int i,shared_ptr<Connection> conn);

	int readNumber(const Connection& conn);

	void protocolBroken();

};
#endif

