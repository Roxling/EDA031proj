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
		//cout << "Sending: " << b-0 <<" "<< b << endl;
		conn.write(b);
	}
}

string readnum(istringstream& iss){
	string arg = "PAR_NUM ";
	string num;
	iss >> num;
	arg+=num;
	return arg;
}

string readstring(istringstream& iss){
	string arg = "PAR_STRING ";
	string str;
	iss >> str;
	arg += to_string(str.size())+" ";
	arg += str;
	return arg;
}
string readtext(istringstream& iss){
	string arg = "PAR_STRING ";
	if(iss){
		// get length
		int start = iss.tellg();
		start++;
		iss.seekg (0, iss.end);
		int length = iss.tellg();
		length -= start;
		iss.seekg (start, iss.beg);
		char * buffer = new char [length];
		iss.read (buffer,length);

		arg += to_string(length)+" ";
		arg += buffer;

		delete[] buffer;
	}

	return arg;
}

struct invalidInputException{};
static string HELP =	"No arguments can contain whitespace except the ones named text. \n"
						"Feedback on invalid command. \n \n"
						"Valid commands: [list|create|delete|get] [article|art|newsgroup|ng] [arguments] \n"
						"list ng \t\t\t - Lists all available newsgroups.  \n"
						"create ng title \t\t - Creates a newsgroup with the provided title. \n"
						"delete ng id \t\t\t - Deletes the newsgroup with the provided id. \n"
						"list art id \t\t\t - Lists all available articles in the newsgroup \n \t\t\t\t associated with the provided id. \n"
						"create art id title author text\t - Creates an article with the \n \t\t\t\t provided title, author and text in the newsgroup \n \t\t\t\t associated with the provided id. \n"
						"delete art ngid artid \t\t - Deletes the article with the provided artid \n \t\t\t\t inside the newsgroup with the provided ngid. \n"
						"get art ngid artid \t\t - Displays the article with the provided artid \n \t\t\t\t inside the newsgroup with the provided ngid. \n";
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
			protocol +=readnum(iss);
		}else if(ng){
			protocol+="NG ";
			protocol += " ";
		}else{
			throw invalidInputException();
		}
	}else if(word.compare("create") == 0){
		protocol+="CREATE_";
		if(art){
			protocol+="ART ";
			protocol+=readnum(iss);
			protocol += " ";
			protocol+=readstring(iss);
			protocol += " ";
			protocol+=readstring(iss);
			protocol += " ";
			protocol+=readtext(iss);
		}else if(ng){
			protocol+="NG ";
			protocol+=readstring(iss);
		}else{
			throw invalidInputException();
		}
	}else if(word.compare("delete") == 0){
		protocol+="DELETE_";
		if(art){
			protocol+="ART ";
			protocol+=readnum(iss);
			protocol += " ";
			protocol+=readnum(iss);
		}else if(ng){
			protocol+="NG ";
			protocol+=readnum(iss);
		}else{
			throw invalidInputException();
		}
	}else if(word.compare("get") == 0){
		protocol+="GET_";
		if(art){
			protocol+="ART ";
			protocol+=readnum(iss);
			protocol += " ";
			protocol+=readnum(iss);
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
		}
		if(b == protocol.PAR_NUM){
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
		}else if(b == protocol.PAR_STRING){
			if(iss >> word){
				try{
					int nbr = stoi(word);
					comm.push_back(nbr >> 24);
					comm.push_back(nbr >> 16);
					comm.push_back(nbr >>  8);
					comm.push_back(nbr);
					iss.get(); //rm whitespace
					for(int i = 0 ; i < nbr; ++i){
						comm.push_back(iss.get());
					}
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
	string comms;
	cout << "Type -help to display help, -quit to exit or enter commands: \n>> ";
	while (getline(cin,comms)) {
		try{
			vector<byte> comm;
			if(comms.find("help") != string::npos && comms.size() < 6){
				cout << HELP << endl;
			}else if(comms.find("quit") != string::npos && comms.size() < 6)
			{
				cout << "Exiting.." << endl;
				exit(0);
			}
			else{
				comm = parseCommand(comms);
				writeCommand(conn, comm);
				cout << rf.createReply(conn)->print() << endl;
			}

		}catch (ConnectionClosedException&) {
			cout << "No reply from server. Exiting." << endl;
			exit(1);
		} catch(ProtocolBrokenException&){
			cout << "Server not following protocol. Can not read answer." << endl;
			while(conn.read() != protocol.ANS_END); //Reading until end.
		}catch(invalidInputException&){
			cout << "Invalid input. Type -help to display help"<<endl;
		}catch(invalid_argument&){
			cout << "Invalid input. Type -help to display help"<<endl;
		}
		cout << ">> ";
	}
}
