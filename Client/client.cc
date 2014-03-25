#include "../connection.h"
#include "../connectionclosedexception.h"
#include "../protocol.h"

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Replies/Reply.h"
#include "Replies/ReplyFactory.h"
#include "../protocolbrokenexception.h"

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
struct invalidInputException{};
static string HELP = "";
string toProtocol(string& input){
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	string protocol="";
	istringstream iss(input);
	string word;
	iss >> word;
	string type;
	iss >> type;

	bool art = type.compare("art") == 0 || type.compare("article") == 0;
	bool ng = type.compare("ng") == 0 || type.compare("newsgroup") == 0 || type.compare("newsgroups") == 0;
	protocol +="COM_";
	if(word.compare("list") == 0){
		protocol+="LIST_";
		if(art){
			protocol+="ART ";
			string id;
			iss >> id;
			protocol +=id;
		}else if(ng){
			protocol+="NG ";
		}else{
			throw invalidInputException();
		}
	}else if(word.compare("create") == 0){
		protocol+="CREATE_";
		if(art){
			protocol+="ART ";
		}else if(ng){
			protocol+="NG ";
		}else{
			throw invalidInputException();
		}
	}else if(word.compare("delete") == 0){
		protocol+="DELETE_";
		if(art){
			protocol+="ART ";
		}else if(ng){
			protocol+="NG ";
		}else{
			throw invalidInputException();
		}
	}else if(word.compare("get") == 0){
		protocol+="GET_";
		if(art){
			protocol+="ART ";
		}else{
			throw invalidInputException();
		}
	}else{
		throw invalidInputException();
	}
	protocol += " COM_END";
	if(iss.fail()){
		throw invalidInputException();
	}
	return protocol;
}

vector<byte> parseCommand(string input){
	vector<byte> comm;
	string command = toProtocol(input);
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
	cout << "Type a commands: \n >> ";
	string command;
	while (getline(cin,command)) {
		try {
			bool correctInput = false;
			vector<byte> comm;
			while(!correctInput){
				try{
					comm = parseCommand(command);
					correctInput = true;
				}catch(invalidInputException&){
					cout << "Invalid input. \n" << ">> ";
				}

			}
			writeCommand(conn, comm);
			cout << rf.createReply(conn)->print() << endl;
			cout << ">> ";
		} catch (ConnectionClosedException&) {
			cout << " no reply from server. Exiting." << endl;
			exit(1);
		} catch(ProtocolBrokenException&){
			cout << "Sever not following protocol. Can not read answer." << endl;
			while(conn.read() != protocol.ANS_END); //Reading until end.
		}
	}
}

