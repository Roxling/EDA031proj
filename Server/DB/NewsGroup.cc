#include <string>
#include <set>
#include "Article.h"
#include "NewsGroup.h"
#include "date.h"
#include <memory>

using namespace std;

NewsGroup::NewsGroup(string namearg):name(namearg),timestamp(Date()){
	static unsigned int counter;
	id = to_string(counter++);
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

vector<pair<string,int>> NewsGroup::listArticles(){
	vector<pair<string,int>> list;
	for(auto pair : articles){
		auto a = pair.second;
		list.push_back(make_pair(a->title, stoi(a->id));
	}
	return list;
}





