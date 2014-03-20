#ifndef NEWSGROUP_H
#define NEWSGROUP_H

#include <string>
#include <unordered_map>
#include "Article.h"
#include <memory>
#include "date.h"

using namespace std;

class NewsGroup{
public:
	NewsGroup(string namearg);
	void addArticle(shared_ptr<Article> a);
	void removeArticle(string artID);
	bool contains(string id);
	string getArticle(string id);
	string listArticles();
	string name;
	string id;
	Date timestamp;
private:
	unordered_map<string,shared_ptr<Article>> articles;

};

#endif
