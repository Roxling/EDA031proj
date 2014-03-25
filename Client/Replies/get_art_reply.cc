#include "Reply.h"
#include <vector>
#include <string>
#include <iostream>
#include "get_art_reply.h"

using byte = char;

get_art_reply::get_art_reply(const Connection& conn){
	vector<string> params;
	byte command = conn.read();
	if(command == protocol.ANS_ACK){
		for(int i = 0 ; i < 3 ; ++i){
			if(conn.read() == protocol.PAR_STRING){
				int length = readNumber(conn);
				string param = "";
				for(int j = 0 ; j < length; ++j){
					param += conn.read();
				}
				params.push_back(param);
			}else{
				protocolBroken();
			}
		}
		ans += "Tile: "+params[0]+" Author: "+params[1]+"\n"+params[2];
	}else if(command == protocol.ANS_NAK){
		byte err = conn.read();
		if(err == protocol.ERR_NG_DOES_NOT_EXIST){
			ans = "NewsGroup does not exist.";
		}else if(err == protocol.ERR_ART_DOES_NOT_EXIST){
			ans = "Article does not exist.";
		}
		else{
			protocolBroken();
		}
	}else{
		protocolBroken();
	}
	if(conn.read() != protocol.ANS_END){
		protocolBroken();
	}
}
	
