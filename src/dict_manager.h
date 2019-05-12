#ifndef WORD_VECTOTS_DICT_MANAGER_H
#define WORD_VECTOTS_DICT_MANAGER_H

#include <unordered_map>
#include "boost/shared_ptr.hpp"
#include "boost/algorithm/string.hpp"


class DictManager {
public:
    DictManager();
    ~DictManager();

public:
    bool Init(const std::string corpus_path);
    std::unordered_map<std::string,int>* GetCorpus();

private:
	bool LoadStopWord();
	bool LoadCorpus();

private:
    std::unordered_map<std::string,int> stop_word_;
    std::unordered_map<std::string,int> corpus_;
    std::string stop_word_path_;
    std::string corpus_path_;
};

#endif //WORD_VECTOTS_DICT_MANAGER_H
