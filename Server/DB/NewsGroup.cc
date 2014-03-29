#include <string>
#include <set>
#include "Article.h"
#include "NewsGroup.h"
#include <memory>
#include <vector>

using namespace std;

unsigned int NewsGroup::counter;

NewsGroup::NewsGroup(string namearg):name(namearg){
	id = NewsGroup::counter++;
}

bool NewsGroup::addArticle(shared_ptr<Article> a){
	return articles.insert(make_pair(a->id,a)).second;
}

bool NewsGroup::removeArticle(int artID){
	return articles.erase(artID);
}

bool NewsGroup::contains(int id){
	return articles.find(id) != articles.end();
}

void NewsGroup::setCounters(int ngcounter,int artcounter){
	NewsGroup::counter = ngcounter;
	Article::counter = artcounter;
}

vector<string> NewsGroup::getArticle(int id){
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
		list.push_back(make_pair(a->title, a->id));
	}

	return list;
}





