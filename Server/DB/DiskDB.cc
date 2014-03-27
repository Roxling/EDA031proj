#include "DiskDB.h"
#include <fstream>

DiskDB::DiskDB(){
	//update NG counter
	//update Art counter
}

bool DiskDB::addNewsGroup(shared_ptr<NewsGroup> ng){

	return false;
}

bool DiskDB::removeNewsGroup(string id) {
	return false;
}

bool DiskDB::containsNewsGroup(string ngID) {
	/*
	 string line;
	 ifstream in("newsgroups.txt");
	 if(myfile.is_open())
	 {
	 while(getline(in,line))
	 {
	 //parsing...
	 cout << line << '\n';
	 }
	 in.close();
	 }else{
	 cout << "Unable to open file";
	 } */
	return false;
}

vector<pair<string, int>> DiskDB::listNewsGroups() {
	return vector<pair<string, int>>();
}
vector<pair<string, int>> DiskDB::listArticles(string ngID) {
	return vector<pair<string, int>>();
}
vector<string> DiskDB::readArticle(string ngID, string artID) {
	return vector<string>();
}

bool DiskDB::addArticle(string ngID, shared_ptr<Article> a) {
	return false;
}

bool DiskDB::removeArticle(string ngID, string artID) {
	return false;
}

bool DiskDB::containsArticle(string ngID, string artID) {
	return false;
}

