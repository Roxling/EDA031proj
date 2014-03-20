#include <string>
#include <iostream>
#include "MemDB.h"
#include <memory>

using namespace std;

int main(){
	MemDB db;
	shared_ptr<NewsGroup> pt(new NewsGroup("g1"));
	db.addNewsGroup(pt);

	string s = db.listNewsGroups();
	cout << s << endl;

}
