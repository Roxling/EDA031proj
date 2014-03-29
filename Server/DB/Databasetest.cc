#include <string>
#include <iostream>
#include <memory>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <errno.h>
#include "DiskDB.h"

using namespace std;
int main(){
	DiskDB();

	/*string ngname = string(entry->d_name);
	try{
		int ngid = stoi(ngname.substr(ngname.find(DELIMITER)));
		cout<<"Name: "+ngname.substr(0,ngname.find(DELIMITER)-1)+" ID: "+to_string(ngid)<<endl;
	}catch(...){};
	while(struct dirent* arts = readdir(newsgroup)){
		string artname = string(arts->d_name);
		try{
			int artid = stoi(artname.substr(artname.find(DELIMITER)));
			cout<<"Name: "+artname.substr(0,artname.find(DELIMITER)-1)+" ID: "+to_string(artid)<<endl;
		}catch(...){};
	}
	closedir(newsgroup);*/
}
