#ifndef MEMDB_H
#define MEMDB_H

#include "Article.h"
#include "NewsGroup.h"
#include "Database.h"
#include <string>
#include <map>
#include "date.h"

using namespace std;

class MemDB: public Database{

public:
	MemDB();

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
	map<string,shared_ptr<NewsGroup>,bool(*)(NewsGroup&,NewsGroup&)> newsgroups([](NewsGroup& lhs, NewsGroup& rhs){return true;});
};

#endif
