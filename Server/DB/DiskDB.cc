#include "DiskDB.h"
#include <fstream>
#include <string>
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

DiskDB::DiskDB(){
	//update NG counter
	//update Art counter
	int maxNgID = 0;
	int maxArtID = 0;
	string root = "DiskDBDir";
	DIR* rootdir = opendir(root.c_str());
	if(!rootdir){
		mkdir(root.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		rootdir = opendir(root.c_str());
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
				if(ngid > maxNgID) maxNgID = ngid;
				cout<<"NewsGroup: "+ng.substr(0,ng.find(DELIMITER))+" ,ID: "+to_string(ngid)<<endl;
			}catch(...){};

			DIR* newsgroup = opendir((root+"/"+ng).c_str());
			readdir(newsgroup); //skips . and ..
			readdir(newsgroup);

			while(struct dirent* article = readdir(newsgroup)){
				struct stat artstat;
				fstatat(dirfd(newsgroup), article->d_name, &artstat, 0);

				if(!S_ISDIR(artstat.st_mode)){
					string art = article->d_name;
					try{
						int artid = stoi(art.substr(art.find(DELIMITER)+1));
						if(artid > maxArtID) maxArtID = artid;
						cout<<"\t Article: "+art.substr(0,art.find(DELIMITER))+" ,ID: "+to_string(artid)<<endl;
					}catch(...){};
				}
			}
			closedir(newsgroup);
		}
	}
	closedir(rootdir);
	cout << maxNgID << " " << maxArtID << endl;
	NewsGroup::setCounters(maxNgID+1,maxArtID+1);
}

bool DiskDB::addNewsGroup(shared_ptr<NewsGroup> ng){

	return false;
}

bool DiskDB::removeNewsGroup(string id) {
	return false;
}

bool DiskDB::containsNewsGroup(string ngID) {
	/*
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
	 } */
	return false;
}

vector<pair<string, int>> DiskDB::listNewsGroups() {
	return vector<pair<string, int>>();
}
vector<pair<string, int>> DiskDB::listArticles(string ngID) {
	return vector<pair<string, int>>();
}
vector<string> DiskDB::readArticle(string ngID, string artID) {
	return vector<string>();
}

bool DiskDB::addArticle(string ngID, shared_ptr<Article> a) {
	return false;
}

bool DiskDB::removeArticle(string ngID, string artID) {
	return false;
}

bool DiskDB::containsArticle(string ngID, string artID) {
	return false;
}

