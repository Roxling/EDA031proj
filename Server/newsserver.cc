#include "server.h"
#include "../connection.h"
#include "../connectionclosedexception.h"
#include "../protocol.h"
#include "Commands/CommandFactory.h"
#include "DB/Database.h"

#include "DB/MemDB.h" //temp?

#include <memory>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <vector>

using namespace std;

using byte = char;

static Protocol protocol;
/*
 * Send a string to a client.
 */
void writeString(const shared_ptr<Connection>& conn, vector<byte>& reply) {
	for (byte b : reply) {
		conn->write(b);
	}
}

vector<byte> readcommand(const shared_ptr<Connection>& conn){
	vector<byte> comm;
	byte b; 	
	do
	{
		b = conn->read();
		comm.push_back(b);
	}while(b != protocol.COM_END);

	return comm;
	
}


int main(int argc, char* argv[]){

	shared_ptr<Database> db(new MemDB()); //Make generalistic

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

	CommandFactory cf(db);

	while (true) {
		auto conn = server.waitForActivity();
		if (conn != nullptr) {
			try {
				auto cmd = readcommand(conn);
				cmd.push_back(protocol.ANS_END);
				//unique_ptr<Command> c = cf.createcommand(cmd);

				//auto reply = c->exec();
				writeString(conn, cmd);
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
