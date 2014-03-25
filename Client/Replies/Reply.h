#ifndef REPLY_H
#define REPLY_H

#include <string>
#include <vector>
#include "../../protocol.h"
#include "../../connection.h"
#include "protocolbrokenexception.h"

using namespace std;
using byte = char;
class Reply{
public:
	virtual string print() = 0;
protected:
	int readNumber(const Connection& conn) {
		return (conn.read() << 24) | (conn.read() << 16) | (conn.read() << 8) | conn.read();
	}

	void protocolBroken(){
		throw ProtocolBrokenException();
	}
	Protocol protocol;
};
#endif

