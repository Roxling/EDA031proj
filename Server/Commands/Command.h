#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "../DB/Database.h"
#include "../../protocol.h"
#include "../../connection.h"
#include "../../protocolbrokenexception.h"

using namespace std;
using byte = char;

class Command{
public:
	Command(){};
	virtual vector<byte>& exec() = 0;
	
protected:
	shared_ptr<Connection> conn;
	vector<byte> ret;
	Protocol p;
	shared_ptr<Database> db;	

	void addParString(string s, shared_ptr<Connection> conn){
		conn->write(p.PAR_STRING);
		conn->write(' ');
		writeNumber(s.size(), conn);
		conn->write(' ');
		for(char c : s){			
			conn->write(c);
		}
	}

	void addParNumber(int i, shared_ptr<Connection> conn){
		conn->write(p.PAR_NUM);
		conn->write(' ');
		writeNumber(i, conn);
	}

	void writeNumber(int i,shared_ptr<Connection> conn){
		conn->write((i >> 24) & 0xFF);
		conn->write((i >> 16) & 0xFF);
		conn->write((i >> 8)	 & 0xFF);
		conn->write(i & 0xFF);
	}

	void throwProtocolException(){
	throw ProtocolBrokenException();
	}

};
#endif

