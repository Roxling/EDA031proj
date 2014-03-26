#ifndef NEWSGROUP_H
#define NEWSGROUP_H

#include <string>
#include <map>
#include "Article.h"
#include <memory>
#include "date.h"
#include <vector>

using namespace std;



class NewsGroup{
public:
	NewsGroup(string namearg);
	bool addArticle(shared_ptr<Article> a);
	bool removeArticle(string artID);
	bool contains(string id);
	vector<string> getArticle(string id);
	vector<pair<string,int>> listArticles();
	string name;
	string id;
	Date timestamp;
private:
	map<string,shared_ptr<Article>> articles;

};

#endif
