#include <string>
#include "NewsGroup.h"
#include "Article.h"
using namespace std;

Article::Article(string authorarg,string titlearg,string textarg):author(authorarg),title(titlearg),text(textarg),timestamp(Date()){
	static unsigned int counter;
	id = to_string(counter++);
}
string Article::getID() const{
	return id;
}


