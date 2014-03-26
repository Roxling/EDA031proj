#ifndef DATABASE_H
#define DATABASE_H

#include "Article.h"
#include "NewsGroup.h"
#include <vector>
#include <string>
#include <memory>
#include "Database.h"
#include <iostream>

using namespace std;

class DiskDB{

public:
	virtual bool addNewsGroup(shared_ptr<NewsGroup> ng) override;
	virtual bool removeNewsGroup(string id) override;
	virtual bool containsNewsGroup(string ngID) override;

	virtual vector<pair<string,int>> listNewsGroups() override;
	virtual vector<pair<string,int>> listArticles(string ngID) override;
	virtual vector<string> readArticle(string ngID,string artID) override;
	
	virtual bool addArticle(string ngID,shared_ptr<Article> a) override;
	virtual bool removeArticle(string ngID,string artID) override;
	virtual bool containsArticle(string ngID,string artID) override;
private:
};

#endif
