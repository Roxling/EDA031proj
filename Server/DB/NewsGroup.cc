#include <string>
#include <set>
#include "Article.h"
#include "NewsGroup.h"
#include <memory>
using namespace std;

NewsGroup::NewsGroup(){
}

void NewsGroup::addArticle(Article* a){
	articles.insert(make_pair(a->id,a));
}

bool NewsGroup::contains(string id){
	return articles.find(id) != articles.end();
}

string NewsGroup::getArticle(string id){
	return "";
}



