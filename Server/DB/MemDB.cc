#include "MemDB.h"
#include "Article.h"
#include "NewsGroup.h"
#include "Database.h"
#include "date.h"
#include <string>
#include <iostream>


using namespace std;

MemDB::MemDB(){}

void MemDB::addNewsGroup(shared_ptr<NewsGroup> ng){
	newsgroups.insert(make_pair(ng->id,ng));
}
void MemDB::removeNewsGroup(string id){
	newsgroups.erase(id);
}

vector<pair<string,int>> MemDB::listNewsGroups(){
	vector<pair<string,int>> list;
	for(auto pair : newsgroups){
		auto ng = pair.second;
		list.push_back(make_pair((ng->name), (stoi(ng->id))));
	}
	return list;	
}
vector<pair<string,int>> MemDB::listArticles(string ngID){
	auto it = newsgroups.find(ngID);
	vector<pair<string,int>> list;
	if(it != newsgroups.end()){
		return it->second->listArticles();
	}
	return list;
}
string MemDB::readArticle(string ngID,string artID){
	auto it = newsgroups.find(ngID);
	string s = "";
	if(it != newsgroups.end()){
		s = it->second->getArticle(artID);
	}
	return s;
}
	
void MemDB::addArticle(string ngID,shared_ptr<Article> a){
	auto it = newsgroups.find(ngID);
	if(it != newsgroups.end()){
		it->second->addArticle(a);
	}
}
void MemDB::removeArticle(string ngID,string artID){
	auto it = newsgroups.find(ngID);
	if(it != newsgroups.end()){
		it->second->removeArticle(artID);
	}
}

