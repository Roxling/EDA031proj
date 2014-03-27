#ifndef ARTICLE_H
#define ARTICLE_H
#include <string>

using namespace std;

class Article{
	friend class NewsGroup;
public:	
	Article(string authorarg,string titlearg,string textarg);
	string getID() const;
private:
	static unsigned int counter;
	string id;
	string author;
	string title;
	string text;
};
#endif
