#include <string>
#include <set>
#include "Article.h"
#include "NewsGroup.h"
#include "date.h"
#include <memory>
#include <vector>

using namespace std;

NewsGroup::NewsGroup(string namearg):name(namearg),timestamp(Date()){
	static unsigned int counter;
	id = to_string(counter++);
}

bool NewsGroup::addArticle(shared_ptr<Article> a){
	return articles.insert(make_pair(a->id,a)).second;
}

bool NewsGroup::removeArticle(string artID){
	return articles.erase(artID);
}

bool NewsGroup::contains(string id){
	return articles.find(id) != articles.end();
}

vector<string> NewsGroup::getArticle(string id){
	vector<string>	v;
	auto it = articles.find(id);
	if(it != articles.end()){
		v.push_back(it->second->title);
		v.push_back(it->second->author);
		v.push_back(it->second->text);
	}
	return v;
}

vector<pair<string,int>> NewsGroup::listArticles(){
	vector<pair<string,int>> list;
	for(auto pair : articles){
		auto a = pair.second;
		list.push_back(make_pair(a->title, stoi(a->id)));
	}
	return list;
}





