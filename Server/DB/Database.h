#ifndef DATABASE_H
#define DATABASE_H

#include "Article.h"
#include "NewsGroup.h"
#include <string>
using namespace std;

class Database{

public:
	virtual void addNewsGroup(NewsGroup* ng) = 0;
	virtual void removeNewsGroup(string id) = 0;

	virtual string listNewsGroups() = 0;
	virtual string listArticles(string ngID) = 0;
	virtual string readArticle(string ngID,string artID) = 0;
	
	virtual void addArticle(string ngID,Article a) = 0;
	virtual void removeArticle(string ngID,string artID) = 0;
private:
	
};

#endif
