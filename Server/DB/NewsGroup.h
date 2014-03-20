#ifndef NEWSGROUP_H
#define NEWSGROUP_H

#include <string>
#include <unordered_map>
#include "Article.h"
#include <memory>

using namespace std;

class NewsGroup{	
public:
	NewsGroup(); //destructor needed?
	void addArticle(Article* a);
	bool contains(string id);
	string getArticle(string id);
private:
	unordered_map<string,Article*> articles;
};

#endif
