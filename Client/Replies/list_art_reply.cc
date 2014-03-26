#include "Reply.h"
#include <vector>
#include <string>
#include <iostream>
#include "list_art_reply.h"

using byte = char;

list_art_reply::list_art_reply(const Connection& conn){
	byte command = conn.read();
	if(command == protocol.ANS_ACK){
		if(conn.read() == protocol.PAR_NUM){
			int numargs = readNumber(conn);
			for(int i = 0; i<numargs; ++i){
				if(conn.read() == protocol.PAR_NUM){
					int id = readNumber(conn);
					ans += "ID: " + to_string(id);
					if(conn.read() == protocol.PAR_STRING){
						int namelength = readNumber(conn);
						ans += " Name: ";
						for(int j = 0; j< namelength ; ++j){
							ans+=conn.read();
						}
						ans += "\n";
					}else{
						protocolBroken();
					}
				}else{
					protocolBroken();
				}
			}
		}else{
			protocolBroken();
		}
	}else if(command == protocol.ANS_NAK){
		if(conn.read() == protocol.ERR_NG_DOES_NOT_EXIST){
			ans = "NewsGroup does not exists.";
		}else{
			protocolBroken();
		}
	}else{
		protocolBroken();
	}
	if(conn.read() != protocol.ANS_END){
		protocolBroken();
	}
}
	
