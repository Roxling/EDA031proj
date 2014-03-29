#ifndef DISKDB_H
#define DISKDB_H

#include "Article.h"
#include "NewsGroup.h"
#include <vector>
#include <string>
#include <memory>
#include "Database.h"
#include <iostream>

using namespace std;

class DiskDB : public Database {

public:
	DiskDB();

	virtual bool addNewsGroup(shared_ptr<NewsGroup> ng) override;
	virtual bool removeNewsGroup(int id) override;
	virtual bool containsNewsGroup(int ngID) override;

	virtual vector<pair<string,int>> listNewsGroups() override;
	virtual vector<pair<string,int>> listArticles(int ngID) override;
	virtual vector<string> readArticle(int ngID,int artID) override;
	
	virtual bool addArticle(int ngID,shared_ptr<Article> a) override;
	virtual bool removeArticle(int ngID,int artID) override;
	virtual bool containsArticle(int ngID,int artID) override;
private:
};

#endif
