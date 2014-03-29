#include "server.h"
#include "../connection.h"
#include "../connectionclosedexception.h"
#include "../protocol.h"
#include "Commands/CommandFactory.h"
#include "DB/Database.h"

#include "DB/MemDB.h"
#include "DB/DiskDB.h"

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


int main(int argc, char* argv[]){
	Database* d;
	if(argc == 3){
		d = new MemDB();
	}else{
		d = new DiskDB();
	}
	shared_ptr<Database> db(d);

	if (argc < 2 || argc > 3 ) {
		cerr << "Usage: myserver port-number memorydatabase (optional, diskdatabase is default)" << endl;
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
				unique_ptr<Command> c = cf.createcommand(conn);
				c->exec();
			} catch (ConnectionClosedException&) {
				server.deregisterConnection(conn);
				cout << "Client closed connection" << endl;
			}catch (ProtocolBrokenException&){
				cout << "Client broke protocol. Kill them." << endl;
				server.deregisterConnection(conn);
			}
		} else {
			conn = make_shared<Connection>();
			server.registerConnection(conn);
			cout << "New client connects" << endl;
		}
	}
}
