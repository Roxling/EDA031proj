#include "Reply.h"
#include <vector>
#include <string>
#include <iostream>
#include "create_art_reply.h"

using byte = char;

create_art_reply::create_art_reply(const Connection& conn){
		byte command = conn.read();
		if(command == protocol.ANS_ACK){
			ans = "Article created.";
		}else if(command == protocol.ANS_NAK){
			if(conn.read() == protocol.ERR_NG_DOES_NOT_EXIST){
				ans = "NewsGroup does not exist.";
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
	
