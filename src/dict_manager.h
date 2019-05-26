#ifndef WORD_VECTOTS_DICT_MANAGER_H
#define WORD_VECTOTS_DICT_MANAGER_H

#include <map>
#include<iostream>

#include "boost/shared_ptr.hpp"
#include "boost/algorithm/string.hpp"

#include"type.h"

class DictManager {
public:
    DictManager();
    ~DictManager();

public:
    bool Init(const std::string corpus_path);
    void DoWork(std::vector<VocabWords>& vocab_words,std::map<std::string,int>& word_hash);

private:
	bool LoadCorpus();
    static bool Comp(VocabWords a, VocabWords b);

private:
    std::map<std::string,int> corpus_;
    std::string corpus_path_;
};

#endif //WORD_VECTOTS_DICT_MANAGER_H
