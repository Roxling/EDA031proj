#include "Reply.h"
#include <vector>
#include <string>
#include <iostream>
#include "delete_art_reply.h"

using byte = char;

delete_art_reply::delete_art_reply(const Connection& conn){
	byte command = conn.read();
	if(command == protocol.ANS_ACK){
		ans = "Article deleted.";
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
	
