#include "protocol.h"
#include <unordered_map>
#include <string>

Protocol::Protocol(){
	protocol.insert({"COM_LIST_NG","1"});
	protocol.insert({"COM_CREATE_NG","2"});
	protocol.insert({"COM_DELETE_NG","3"});
	protocol.insert({"COM_LIST_ART","4"});
	protocol.insert({"COM_CREATE_ART","5"});
	protocol.insert({"COM_DELETE_ART","6"});
	protocol.insert({"COM_GET_ART","7"});
	protocol.insert({"COM_END","8"});

	protocol.insert({"ANS_LIST_NG","20"});
	protocol.insert({"ANS_CREATE_NG","21"});
	protocol.insert({"ANS_DELETE_NG","22"});
	protocol.insert({"ANS_LIST_ART","23"});
	protocol.insert({"ANS_CREATE_ART","24"});
	protocol.insert({"ANS_DELETE_ART","25"});
	protocol.insert({"ANS_GET_ART","26"});
	protocol.insert({"ANS_END","27"});
	protocol.insert({"ANS_ACK","28"});
	protocol.insert({"ANS_NAK","29"});
	
	protocol.insert({"PAR_STRING","40"});
	protocol.insert({"PAR_NUM","41"});

	protocol.insert({"ERR_NG_ALREADY_EXISTS","50"});
	protocol.insert({"ERR_NG_DOES_NOT_EXIST","51"});
	protocol.insert({"ERR_ART_DOES_NOT_EXIST","52"});
}

int Protocol::getByte(string command){
	auto it = protocol.find(command);
	if(it != protocol.end())
		return stoi(it->second);
 	return -1;
}
