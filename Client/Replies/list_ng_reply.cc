#include "Reply.h"
#include <vector>
#include <string>
#include <iostream>
#include "list_ng_reply.h"

using byte = char;

list_ng_reply::list_ng_reply(vector<byte>& c): comm(c){
	ans = "";
	if(comm.size() >= minsize){
		if(comm[1] == protocol.PAR_NUM){				
			int numargs = readNumber(comm,2);
			unsigned int index = 6;				
			for(int i = 0; i< numargs; ++i){
				ans += "ID: ";
				index +=1;
				int ID = readNumber(comm,index);
				ans += to_string(ID);
				index += 5;
				int length = readNumber(comm,index);
				index += 4;
				ans += " Name: ";
				for(int j = 0 ; j < length ; ++j){
					char ch = comm[index+j];
					ans += comm[index+j];
				}
				index += length;
				ans += "\n";
			}
		}
	}
	
}
	
