#ifndef ARTICLE_H
#define ARTICLE_H
#include <string>


using namespace std;

class Article{
	friend class NewsGroup;
public:	
	Article(string idarg,string authorarg,string textarg);
private:	
	string id;
	string author;
	string text;
	string timestamp;
	
};

#endif
