#ifndef MEMDB_H
#define MEMDB_H

#include "Article.h"
#include "NewsGroup.h"
#include "Database.h"
#include <string>
#include <map>

using namespace std;


class MemDB: public Database{

public:
	MemDB();

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
	map<int,shared_ptr<NewsGroup>> newsgroups;
};

#endif
