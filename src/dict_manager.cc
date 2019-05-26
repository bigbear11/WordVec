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
    bool status=LoadCorpus();

    return status;
}

void DictManager::DoWork(std::vector<VocabWords>& vocab_words,std::map<std::string,int>& word_hash){
    map<std::string,int>::iterator it = corpus_.begin();
    while(it != corpus_.end()) {
        VocabWords vocab_word;
        //std::cout<<it->first<<" "<<it->second<<std::endl;
        vocab_word.cn=it->second;
        vocab_word.word=it->first;
        vocab_words.push_back(vocab_word);
        it++;
        }
        sort(vocab_words.begin(),vocab_words.end(),Comp);
    for(int idx=0;idx<vocab_words.size();idx++){
        word_hash[vocab_words.word]=idx;
    }

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
        std::cout<<items.size()<<std::endl;
        for(int idx=0;idx<items.size();idx++){
		    if(corpus_.count(items[idx])>0){
                corpus_[items[idx]]=corpus_[items[idx]]+1;
                }
            else{
                corpus_[items[idx]]=1;
                }
        }
	}
	return true;
}

bool DictManager::Comp(VocabWords a, VocabWords b) {
    return a.cn > b.cn;
    }
