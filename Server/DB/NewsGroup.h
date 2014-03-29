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
	bool removeArticle(int artID);
	bool contains(int id);
	vector<string> getArticle(int id);
private:
	static void setCounters(int ngcounter,int artcounter);
	static unsigned int counter;
	vector<pair<string,int>> listArticles();
	int id;
	string name;
	map<int,shared_ptr<Article>> articles;

};


#endif
