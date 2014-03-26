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
	Command(shared_ptr<Database>& database, shared_ptr<Connection>& c);
	virtual void exec() = 0;
	
protected:
	shared_ptr<Database> db;
	shared_ptr<Connection> conn;
	Protocol protocol;

	void addParString(string s, shared_ptr<Connection> conn);

	void addParNumber(int i, shared_ptr<Connection> conn);

	void writeNumber(int i,shared_ptr<Connection> conn);
	
	string readString(const Connection& conn);

	int readNumber(const Connection& conn);

	void protocolBroken();

};
#endif

