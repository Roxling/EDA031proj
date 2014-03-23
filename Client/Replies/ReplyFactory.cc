#include "ReplyFactory.h"
#include "no_reply.h"
#include "list_ng_reply.h"

#include <iostream>
#include <vector>

using namespace std;
using byte = char;

unique_ptr<Reply> ReplyFactory::createReply(vector<byte>& comm){
	if(comm.empty())
		return unique_ptr<Reply>(new no_reply());

	byte b = comm.front();
	switch(b-0){
	case protocol.ANS_LIST_NG:
		return unique_ptr<Reply>(new list_ng_reply(comm));
		break;
	}

	return unique_ptr<Reply>(new no_reply());
}
