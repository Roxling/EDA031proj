#include "Reply.h"
#include <vector>
#include <string>
#include <iostream>
#include "delete_ng_reply.h"

using byte = char;

delete_ng_reply::delete_ng_reply(const Connection& conn){
	byte command = conn.read();
	if(command == protocol.ANS_ACK){
		ans = "NewsGroup deleted.";
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
	
