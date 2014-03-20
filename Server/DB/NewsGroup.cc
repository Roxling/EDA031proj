#include <string>
#include <set>
#include "Article.h"
#include "NewsGroup.h"
#include <memory>
using namespace std;

NewsGroup::NewsGroup(string idarg): id(idarg){
}

void NewsGroup::addArticle(shared_ptr<Article> a){
	articles.insert(make_pair(a->id,a));
}

void NewsGroup::removeArticle(string artID){
	articles.erase(artID);
}

bool NewsGroup::contains(string id){
	return articles.find(id) != articles.end();
}

string NewsGroup::getArticle(string id){
	string s = "";
	auto it = articles.find(id);
	if(it != articles.end()){
		s += it->second->author+"\n"+it->second->text;
	}
	return s;
}

string NewsGroup::listArticles(){
	string s = "";
	for(auto pair : articles){
		auto a = pair.second;
		s+= a->title + " by " + a->author + " ID: " + a->id+"\n"; 

	}
	return "";
}





