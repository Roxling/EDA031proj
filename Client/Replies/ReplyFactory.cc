#include "ReplyFactory.h"
#include "no_reply.h"
#include "list_ng_reply.h"
#include "create_ng_reply.h"
#include "delete_ng_reply.h"
#include "list_art_reply.h"
#include "create_art_reply.h"
#include "delete_art_reply.h"
#include "get_art_reply.h"
#include "../../connection.h"
#include <iostream>
#include <vector>

using namespace std;
using byte = char;

unique_ptr<Reply> ReplyFactory::createReply(const Connection& conn){


	switch(conn.read()-0){
	case protocol.ANS_LIST_NG:
		return unique_ptr<Reply>(new list_ng_reply(conn));
	case protocol.ANS_CREATE_NG:
		return unique_ptr<Reply>(new create_ng_reply(conn));
	case protocol.ANS_DELETE_NG:
		return unique_ptr<Reply>(new delete_ng_reply(conn));
	case protocol.ANS_LIST_ART:
		return unique_ptr<Reply>(new list_art_reply(conn));
	case protocol.ANS_CREATE_ART:
			return unique_ptr<Reply>(new create_art_reply(conn));
	case protocol.ANS_DELETE_ART:
			return unique_ptr<Reply>(new delete_art_reply(conn));
	case protocol.ANS_GET_ART:
			return unique_ptr<Reply>(new get_art_reply(conn));
	}

	return unique_ptr<Reply>(new no_reply());
}
