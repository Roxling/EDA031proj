#ifndef MEMDB_H
#define MEMDB_H

#include "Article.h"
#include "NewsGroup.h"
#include "Database.h"
#include <string>
#include <unordered_map>
#include "date.h"

using namespace std;

class MemDB: public Database{

public:
	MemDB();

	virtual bool addNewsGroup(shared_ptr<NewsGroup> ng) override;
	virtual void removeNewsGroup(string id) override;

	virtual vector<pair<string,int>> listNewsGroups() override;
	virtual vector<pair<string,int>> listArticles(string ngID) override;
	virtual string readArticle(string ngID,string artID) override;
	
	virtual void addArticle(string ngID,shared_ptr<Article> a) override;
	virtual void removeArticle(string ngID,string artID) override;
private:
	unordered_map<string,shared_ptr<NewsGroup>> newsgroups;
};

#endif
