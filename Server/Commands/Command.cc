#include <string>
#include "../DB/Database.h"
#include "../../protocol.h"
#include "../../connection.h"
#include "../../protocolbrokenexception.h"
#include <iostream>
#include <Command.h>

using namespace std;
using byte = char;

Command::Command(shared_ptr<Database> db2, shared_ptr<Connection> c):db(db2),conn(c){}
	

void Command::addParString(string s, shared_ptr<Connection> conn){
	conn->write(protocol.PAR_STRING);
	writeNumber(s.size(), conn);
	for(char c : s){
		conn->write(c);
	}
}

void Command::addParNumber(int i, shared_ptr<Connection> conn){
	conn->write(protocol.PAR_NUM);
	writeNumber(i, conn);
}

void Command::writeNumber(int i,shared_ptr<Connection> conn){
	conn->write((i >> 24) & 0xFF);
	conn->write((i >> 16) & 0xFF);
	conn->write((i >> 8)  & 0xFF);
	conn->write(i & 0xFF);
}

int Command::readNumber(const Connection& conn) {
	return (conn.read() << 24) | (conn.read() << 16) | (conn.read() << 8) | conn.read();
}

void Command::protocolBroken(){
	throw ProtocolBrokenException();
}


