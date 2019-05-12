#include <fstream>
#include <string>

#include "dict_manager.h"
using namespace std;
using namespace boost::algorithm;


DictManager::DictManager(){
	
}

DictManager::~DictManager(){

}

bool DictManager::Init(const std::string corpus_path){
    corpus_path_=corpus_path;

    return true;
}

std::unordered_map<std::string,int>* DictManager::GetCorpus(){
    return &corpus_;
}


bool DictManager::LoadStopWord(){
	//open
	std::ifstream in(stop_word_path_.c_str());
	if(!in.is_open()){
		cout << "open file " << stop_word_path_ <<" failed"<<endl;
		return false;
	}

	char buffer[1024];
	string line;
	while(getline(in,line)){
		if(stop_word_.count(line)>1) continue;				
		stop_word_[line]=1;
	}
	in.close();
	return true;
}

bool DictManager::LoadCorpus(){
	//open
	std::ifstream in(corpus_path_.c_str());
	if(!in.is_open()){
		cout << "open file " << corpus_path_ <<" failed"<<endl;
		return false;
	}
	string line;
	while(getline(in,line)){
        std::vector<std::string> items;
        split(items,line,boost::is_any_of(" "));
        for(int idx=0;idx<items.size();idx++){
            std::cout<<"word:"<<items[idx];
		    if(corpus_.count(items[idx])>1){
                corpus_[items[idx]]=corpus_[items[idx]]+1;
                }
        else{
                corpus_[items[idx]]=1;
                }
        }
	}
	return true;
}

