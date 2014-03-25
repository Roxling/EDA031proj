#include "Reply.h"
#include <vector>
#include <string>
#include <iostream>
#include "list_ng_reply.h"

using byte = char;

list_ng_reply::list_ng_reply(const Connection& conn){
	if(conn.read() == protocol.PAR_NUM){
		int numargs = readNumber(conn);
		for(int i = 0; i<numargs; ++i){
			if(conn.read() == protocol.PAR_NUM){
				int id = readNumber(conn);
				ans += "ID: " + to_string(id);
				if(conn.read() == protocol.PAR_STRING){
					int namelength = readNumber(conn);
					ans += "Name: ";
					for(int j = 0; j< namelength ; ++j){
						ans+=conn.read();
					}
				}else{
					protocolBroken();
				}
			}else{
				protocolBroken();
			}
		}
		if(conn.read() != protocol.ANS_END){
			protocolBroken();
		}
	}else{
		protocolBroken();
	}

}
	
