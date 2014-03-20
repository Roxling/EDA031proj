#ifndef ARTICLE_H
#define ARTICLE_H
#include <string>
#include "date.h"

using namespace std;

class Article{
	friend class NewsGroup;
public:	
	Article(string authorarg,string titlearg,string textarg);
private:	
	string id;
	string author;
	string title;
	string text;
	Date timestamp;
	
};

#endif
