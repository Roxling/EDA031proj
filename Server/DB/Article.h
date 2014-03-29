#ifndef ARTICLE_H
#define ARTICLE_H
#include <string>

using namespace std;

class Article{
	friend class NewsGroup;
	friend class DiskDB;
public:
	Article(string authorarg,string titlearg,string textarg);
	int getID() const;
private:
	static unsigned int counter;
	int id;
	string author;
	string title;
	string text;
};
#endif
