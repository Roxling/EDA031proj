#ifndef NO_COMMAND_H
#define NO_COMMAND_H


#include "Command.h"

class no_command : public Command {
public:
	virtual vector<byte>& exec() override{
		cout << "Faulty Command!" << endl;
		return ret;
		//TODO Terminate client
	};
};

#endif
