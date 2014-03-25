#include "../connection.h"
#include "../connectionclosedexception.h"
#include "../protocol.h"

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include "Replies/Reply.h"
#include "Replies/ReplyFactory.h"

using namespace std;

using byte = char;
static Protocol protocol;
/*
 * Send a string to the server.
 */
void writeCommand(const Connection& conn, vector<byte>& command) {
	for(byte b : command){
		cout << "Send: " << b-0 << endl;		
		conn.write(b);
	}
}

vector<byte> parseCommand(string command){
	vector<byte> comm;
	istringstream iss(command);
	string word;
	while(iss >> word){
		byte b = protocol.getByte(word);
		if(b != protocol.ERR_NOT_PROTOCOL){
			comm.push_back(b);
		}else{
			for(byte ch : word){
				comm.push_back(ch);
			}
		}
		if(b == protocol.PAR_STRING || b == protocol.PAR_NUM){
			if(iss >> word){
				try{
					int nbr = stoi(word);
					comm.push_back(nbr >> 24);
    				comm.push_back(nbr >> 16);
    				comm.push_back(nbr >>  8);
    				comm.push_back(nbr);
				}catch(out_of_range& e){
					cout << "Parse int to byte[] error" << endl;
				}
			}
		}
	}
	if(comm.empty() || comm.back() != protocol.COM_END){
		comm.push_back(protocol.COM_END);
	}

	return comm;
}	


int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "Usage: myclient host-name port-number" << endl;
		exit(1);
	}

	int port = -1;
	try {
		port = stoi(argv[2]);
	} catch (exception& e) {
		cerr << "Wrong port number. " << e.what() << endl;
		exit(1);
	}

	Connection conn(argv[1], port);
	if (!conn.isConnected()) {
		cerr << "Connection attempt failed" << endl;
		exit(1);
	}
	ReplyFactory rf;
	cout << "Type a command: ";
	string command;
	while (getline(cin,command)) {
		try {
			auto comm = parseCommand(command); 
			writeCommand(conn, comm);
			cout << rf.createReply(conn)->print() << endl;
			cout << ">>";
		} catch (ConnectionClosedException&) {
			cout << " no reply from server. Exiting." << endl;
			exit(1);
		}
	}
}
