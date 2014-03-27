#ifndef NEWSGROUP_H
#define NEWSGROUP_H

#include <string>
#include <map>
#include "Article.h"
#include <memory>
#include <vector>

using namespace std;



class NewsGroup{
	friend class MemDB;
	friend class DiskDB;
public:
	NewsGroup(string namearg);
	bool addArticle(shared_ptr<Article> a);
	bool removeArticle(string artID);
	bool contains(string id);
	vector<string> getArticle(string id);
private:
	static void setCounters(int ngcounter,int artcounter);
	static unsigned int counter;
	vector<pair<string,int>> listArticles();
	string id;
	string name;
	map<string,shared_ptr<Article>> articles;

};


#endif
