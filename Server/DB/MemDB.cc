#include "MemDB.h"
#include "Article.h"
#include "NewsGroup.h"
#include "Database.h"
#include <string>


using namespace std;

MemDB::MemDB(){}

void MemDB::addNewsGroup(NewsGroup* ng){}
void MemDB::removeNewsGroup(string id){}

string MemDB::listNewsGroups(){}
string MemDB::listArticles(string ngID){}
string MemDB::readArticle(string ngID,string artID){}
	
void MemDB::addArticle(string ngID,Article a){}
void MemDB::removeArticle(string ngID,string artID){}

