#ifndef REPLYFACTORY_H
#define REPLYFACTORY_H

#include "Reply.h"
#include <string>
#include <memory>
#include <vector>
#include "../../protocol.h"

using namespace std;
using byte = char;
class ReplyFactory{
public:
	std::unique_ptr<Reply> createReply(vector<byte>& comm);
private:
	Protocol protocol;
};


#endif
