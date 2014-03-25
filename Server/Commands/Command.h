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
	Command(){};
	virtual void exec() = 0;
	
protected:
	shared_ptr<Connection> conn;
	vector<byte> ret;
	Protocol p;
	shared_ptr<Database> db;	

	void addParString(string s, shared_ptr<Connection> conn){
		conn->write(p.PAR_STRING);
		writeNumber(s.size(), conn);
		for(char c : s){			
			conn->write(c);
		}
	}

	void addParNumber(int i, shared_ptr<Connection> conn){
		conn->write(p.PAR_NUM);
		writeNumber(i, conn);
	}

	void writeNumber(int i,shared_ptr<Connection> conn){
		conn->write((i >> 24) & 0xFF);
		conn->write((i >> 16) & 0xFF);
		conn->write((i >> 8)	 & 0xFF);
		conn->write(i & 0xFF);
	}

	int readNumber(const Connection& conn) {
		return (conn.read() << 24) | (conn.read() << 16) | (conn.read() << 8) | conn.read();
	}

	void throwProtocolException(){
	throw ProtocolBrokenException();
	}

};
#endif

