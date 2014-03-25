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

	void add parString(String s, vector<byte>& v){


	}

	void add parNumber(int i, vector<byte>& v){
		v.push_back(p.PAR_NUM);
		v.push_back(' ');
		ret.push_back((i >> 24) & 0xFF);
		conn.write((value >> 16) & 0xFF);
	conn.write((value >> 8)	 & 0xFF);
	conn.write(value & 0xFF);
	


	}

};
#endif

