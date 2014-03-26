#include "DiskDB.h"
#include <fstream>


bool DiskDB::addNewsGroup(shared_ptr<NewsGroup> ng){
	

}

bool DiskDB::removeNewsGroup(string id){

}

bool DiskDB::containsNewsGroup(string ngID){	

	string line;
	ifstream in("newsgroups.txt");
	if(myfile.is_open())
	{
		while(getline(in,line))
		{
			//parsing...
	   		cout << line << '\n';
		}
	in.close();
	}else{
		cout << "Unable to open file"; 
	}
}

vector<pair<string,int>> DiskDB::listNewsGroups(){

}
vector<pair<string,int>> DiskDB::listArticles(string ngID){

}
vector<string> DiskDB::readArticle(string ngID,string artID){

}
	
bool DiskDB::addArticle(string ngID,shared_ptr<Article> a){

}

bool DiskDB::removeArticle(string ngID,string artID){

}

bool DiskDB::containsArticle(string ngID,string artID){

}

	

