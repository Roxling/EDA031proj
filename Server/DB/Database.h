#ifndef DATABASE_H
#define DATABASE_H

#include "Article.h"
#include "NewsGroup.h"
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Database{

public:
	virtual bool addNewsGroup(shared_ptr<NewsGroup> ng) = 0;
	virtual bool removeNewsGroup(string id) = 0;
	virtual bool containsNewsGroup(string ngID) = 0;

	virtual vector<pair<string,int>> listNewsGroups() = 0;
	virtual vector<pair<string,int>> listArticles(string ngID) = 0;
	virtual string readArticle(string ngID,string artID) = 0;
	
	virtual bool addArticle(string ngID,shared_ptr<Article> a) = 0;
	virtual bool removeArticle(string ngID,string artID) = 0;
	virtual bool containsArticle(string ngID,string artID) = 0;
private:
	
};

#endif
