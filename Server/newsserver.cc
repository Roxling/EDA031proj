#include "server.h"
#include "../connection.h"
#include "../connectionclosedexception.h"
#include "../protocol.h"
#include "Commands/CommandFactory.h"
#include "DB/Database.h"


#include <memory>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>

using namespace std;

using byte = char;
/*
 * Send a string to a client.
 */
void writeString(const shared_ptr<Connection>& conn, const string& s) {
	for (char c : s) {
		conn->write(c);
		
	}
	conn->write('$');
}

string readcommand(const shared_ptr<Connection>& conn){

	string cmdstring;
	
	while(unsigned char b = conn->read()){
		cmdstring += b;
	}
	
	return cmdstring;
	
}


int main(int argc, char* argv[]){

	unique_ptr<Database> db(new Database());

	if (argc != 2) {
		cerr << "Usage: myserver port-number" << endl;
		exit(1);
	}
	
	int port = -1;
	try {
		port = stoi(argv[1]);
	} catch (exception& e) {
		cerr << "Wrong port number. " << e.what() << endl;
		exit(1);
	}
	
	Server server(port);
	if (!server.isReady()) {
		cerr << "Server initialization error." << endl;
		exit(1);
	}

	CommandFactory cf;

	while (true) {
		auto conn = server.waitForActivity();
		if (conn != nullptr) {
			try {
				string cmdstring = readcommand(conn);
				cout << cmdstring << endl;
				unique_ptr<Command> c = cf.createcommand(*((cmdstring.substr(0,1)).c_str()));
				string reply = c->exec(cmdstring,db);
				writeString(conn, reply);
			} catch (ConnectionClosedException&) {
				server.deregisterConnection(conn);
				cout << "Client closed connection" << endl;
			}
		} else {
			conn = make_shared<Connection>();
			server.registerConnection(conn);
			cout << "New client connects" << endl;
		}
	}
}
