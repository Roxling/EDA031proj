#include "Reply.h"
#include <vector>
#include <string>
#include <iostream>
#include "create_ng_reply.h"

using byte = char;

create_ng_reply::create_ng_reply(const Connection& conn){
	byte command = conn.read();
	if(command == protocol.ANS_ACK){
		ans = "Creation successful.";
	}else if(command == protocol.ANS_NAK){
		if(conn.read() == protocol.ERR_NG_ALREADY_EXISTS){
			ans = "NewsGroup already exists.";
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
	
