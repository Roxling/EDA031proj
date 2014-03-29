#include <string>
#include "NewsGroup.h"
#include "Article.h"
using namespace std;

unsigned int Article::counter;

Article::Article(string authorarg,string titlearg,string textarg):author(authorarg),title(titlearg),text(textarg){
	id = Article::counter++;
}
int Article::getID() const{
	return id;
}


