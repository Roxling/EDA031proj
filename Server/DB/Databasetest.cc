#include <string>
#include <iostream>
#include "MemDB.h"
#include <memory>

using namespace std;

int main(){
	MemDB db;
	shared_ptr<NewsGroup> pt1(new NewsGroup("g1"));
	shared_ptr<NewsGroup> pt2(new NewsGroup("g2"));
	shared_ptr<NewsGroup> pt3(new NewsGroup("g3"));
	db.addNewsGroup(pt1);
	db.addNewsGroup(pt2);
	db.addNewsGroup(pt3);

	
	string s = db.listNewsGroups();
	cout << s << endl;

}
