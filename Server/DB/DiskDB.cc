#include "DiskDB.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <memory>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <errno.h>

const static string DELIMITER = "=";
const static string ROOT = "DiskDBDir";

DiskDB::DiskDB(){
	//update NG counter
	//update Art counter
	int maxNgID = 0;
	int maxArtID = 0;
	DIR* rootdir = opendir(ROOT.c_str());
	if(!rootdir){
		mkdir(ROOT.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		rootdir = opendir(ROOT.c_str());
	}
	closedir(rootdir);
	for(auto ng : DiskDB::listNewsGroups()){
		if(ng.second>maxNgID) maxNgID = ng.second;
		for(auto art : DiskDB::listArticles(ng.second)){
			if(art.second>maxArtID) maxArtID = ng.second;
		}
	}
	NewsGroup::setCounters(maxNgID+1,maxArtID+1);
}

bool DiskDB::addNewsGroup(shared_ptr<NewsGroup> ng){
	for(auto pair : DiskDB::listNewsGroups()){
		if(pair.first.compare(ng->name) == 0 || pair.second == ng->id){
			return false;
		}
	}
	mkdir((ROOT+"/"+ng->name+DELIMITER+to_string(ng->id)).c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	return true;
}

bool DiskDB::removeNewsGroup(int id) {
	for(auto pair : DiskDB::listNewsGroups()){
		if(pair.second == id){
			string command = "rm -rf ";
			command += '"';
			command +=(ROOT+"/"+pair.first+DELIMITER+to_string(id));
			command += '"';
			return system(command.c_str()) == 0;
		}
	}
	return false;
}

bool DiskDB::containsNewsGroup(int ngID) {
	for(auto pair : DiskDB::listNewsGroups()){
		if(pair.second == ngID){
			return true;
		}
	}
	return false;
}

vector<pair<string, int>> DiskDB::listNewsGroups() {
	vector<pair<string, int>> newsgroups;
	DIR* rootdir = opendir(ROOT.c_str());
	if(!rootdir){
		mkdir(ROOT.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		rootdir = opendir(ROOT.c_str());
	}
	readdir(rootdir); //skips . and ..
	readdir(rootdir);
	while(struct dirent* entry = readdir(rootdir)){
		string ng = entry->d_name;
		struct stat dirstat;
		fstatat(dirfd(rootdir), entry->d_name, &dirstat, 0);

		if (S_ISDIR(dirstat.st_mode)){
			try{
				int ngid = stoi(ng.substr(ng.find(DELIMITER)+1));
				string ngname = ng.substr(0,ng.find(DELIMITER));
				newsgroups.push_back(make_pair(ngname,ngid));
			}catch(...){};
		}
	}
	closedir(rootdir);
	sort(newsgroups.begin(),newsgroups.end(),[](const pair<string,int>& p1,const pair<string,int>& p2){return p1.second<p2.second;});
	return newsgroups;
}
vector<pair<string, int>> DiskDB::listArticles(int ngID) {
	vector<pair<string, int>> articles;
	for(auto pair : DiskDB::listNewsGroups()){
		if(pair.second == ngID){
			DIR* newsgroup = opendir((ROOT+"/"+pair.first+DELIMITER+to_string(ngID)).c_str());
			if(newsgroup){
				readdir(newsgroup); //skips . and ..
				readdir(newsgroup);

				while(struct dirent* article = readdir(newsgroup)){
					struct stat artstat;
					fstatat(dirfd(newsgroup), article->d_name, &artstat, 0);

					if(!S_ISDIR(artstat.st_mode)){
						string art = article->d_name;
						try{
							int artid = stoi(art.substr(art.find(DELIMITER)+1));
							string artname = art.substr(0,art.find(DELIMITER));
							articles.push_back(make_pair(artname,artid));
						}catch(...){};
					}
				}
				closedir(newsgroup);
			}
			break;
		}
	}
	sort(articles.begin(),articles.end(),[](const pair<string,int>& p1,const pair<string,int>& p2){return p1.second<p2.second;});
	return articles;
}
vector<string> DiskDB::readArticle(int ngID, int artID) {
	vector<string> content;
	for(auto pair : DiskDB::listNewsGroups()){
		if(pair.second == ngID){
			for(auto art : DiskDB::listArticles(ngID)){
				if(art.second == artID){
					ifstream file;
					file.open( ROOT+"/"+pair.first+DELIMITER+to_string(ngID)+"/"+art.first+DELIMITER+to_string(artID));

					content.push_back(art.first);
					string s;
					getline(file,s);
					content.push_back(s);
					string total = "";
					while(!file.eof()){
						getline(file,s);
						total += s;
						if(!file.eof()) total+='\n';
					}
					content.push_back(total);
					file.close();
				}

			}

			break;
		}

	}


	return content;
}

bool DiskDB::addArticle(int ngID, shared_ptr<Article> a) {
	ofstream file;
	if(DiskDB::containsArticle(ngID,a->getID())) return false;
	for(auto pair : DiskDB::listNewsGroups()){
		if(pair.second == ngID){
			file.open( ROOT+"/"+pair.first+DELIMITER+to_string(ngID)+"/"+a->title+DELIMITER+to_string(a->id) );
			file << a->author << "\n"<< a->text;
			file.close();
			return true;
		}

	}

	return false;
}

bool DiskDB::removeArticle(int ngID, int artID) {
	string ngname="";
	for(auto pair : DiskDB::listNewsGroups()){
		if(pair.second == ngID){
			ngname = pair.first;
			for(auto pair : DiskDB::listArticles(ngID)){
				if(pair.second == artID){
					string command = "rm -rf ";
					command += '"';
					command +=(ROOT+"/"+ngname+DELIMITER+to_string(ngID)+"/"+pair.first+DELIMITER+to_string(pair.second));
					command += '"';
					return system(command.c_str()) == 0;
				}
			}
			break;
		}
	}
	return false;
}

bool DiskDB::containsArticle(int ngID, int artID) {
	for(auto pair : DiskDB::listArticles(ngID)){
		if(pair.second == artID){
			return true;
		}
	}
	return false;
}

