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
	DiskDB db;
	for(auto pair : db.listNewsGroups()){
		cout << pair.first << " " << pair.second << endl;
	}
	db.readArticle("2","23");
}
