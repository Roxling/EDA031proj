#include "MemDB.h"
#include "Article.h"
#include "NewsGroup.h"
#include "Database.h"
#include <string>
#include <iostream>
#include <vector>


using namespace std;

MemDB::MemDB(){
}

bool MemDB::addNewsGroup(shared_ptr<NewsGroup> ng){
	for(auto n : newsgroups){
		if(n.second->name.compare(ng->name) == 0){
			return false;
		}
	}
	return newsgroups.insert(make_pair(ng->id,ng)).second;
}
bool MemDB::removeNewsGroup(int id){
	return newsgroups.erase(id);;
}

bool  MemDB::containsArticle(int ngID,int artID){
	auto it =  newsgroups.find(ngID);
	if(it != newsgroups.end()){
		return it->second->contains(artID);
	}
	return false;
}

bool  MemDB::containsNewsGroup(int ngID){
	return newsgroups.find(ngID) != newsgroups.end();
}

vector<pair<string,int>> MemDB::listNewsGroups(){
	vector<pair<string,int>> list;
	for(auto pair : newsgroups){
		auto ng = pair.second;
		list.push_back(make_pair((ng->name), ng->id));
	}
	return list;	
}
vector<pair<string,int>> MemDB::listArticles(int ngID){
	auto it = newsgroups.find(ngID);
	if(it != newsgroups.end()){
		return it->second->listArticles();
	}
	return vector<pair<string,int>>();
}
vector<string> MemDB::readArticle(int ngID,int artID){
	auto it = newsgroups.find(ngID);
	if(it != newsgroups.end()){
		return it->second->getArticle(artID);
	}
	return vector<string>();
}
	
bool MemDB::addArticle(int ngID,shared_ptr<Article> a){
	auto it = newsgroups.find(ngID);
	if(it != newsgroups.end()){
		it->second->addArticle(a);
		return true;
	}
	return false;
}
bool MemDB::removeArticle(int ngID,int artID){
	auto it = newsgroups.find(ngID);
	if(it != newsgroups.end()){
		return it->second->removeArticle(artID);
	}
	return false;
}

