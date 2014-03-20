#ifndef ARTICLE_H
#define ARTICLE_H
#include <string>


using namespace std;

class Article{
	friend class NewsGroup;
public:	
	Article(string idarg,string authorarg,string titlearg,string textarg);
private:	
	string id;
	string author;
	string title;
	string text;
	string timestamp;
	
};

#endif
