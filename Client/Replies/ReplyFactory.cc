#include "ReplyFactory.h"
#include "no_reply.h"
#include "list_ng_reply.h"
#include "../../connection.h"
#include <iostream>
#include <vector>

using namespace std;
using byte = char;

unique_ptr<Reply> ReplyFactory::createReply(const Connection& conn){


	switch(conn.read()-0){
	case protocol.ANS_LIST_NG:
		return unique_ptr<Reply>(new list_ng_reply(conn));
		break;
	}

	return unique_ptr<Reply>(new no_reply());
}
