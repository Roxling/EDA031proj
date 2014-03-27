#include <string>
#include "NewsGroup.h"
#include "Article.h"
using namespace std;

unsigned int Article::counter;

Article::Article(string authorarg,string titlearg,string textarg):author(authorarg),title(titlearg),text(textarg){
	id = to_string(static_cast<int>(Article::counter++));
}
string Article::getID() const{
	return id;
}


