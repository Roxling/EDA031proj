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
	virtual bool removeNewsGroup(int id) = 0;
	virtual bool containsNewsGroup(int ngID) = 0;

	virtual vector<pair<string,int>> listNewsGroups() = 0;
	virtual vector<pair<string,int>> listArticles(int ngID) = 0;
	virtual vector<string> readArticle(int ngID,int artID) = 0;
	
	virtual bool addArticle(int ngID,shared_ptr<Article> a) = 0;
	virtual bool removeArticle(int ngID,int artID) = 0;
	virtual bool containsArticle(int ngID,int artID) = 0;
private:
	
};

#endif
