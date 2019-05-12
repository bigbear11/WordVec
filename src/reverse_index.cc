#include "reverse_index.h"


ReverseIndex::ReverseIndex()
{

}
ReverseIndex::~ReverseIndex()
{

}

bool ReverseIndex::insert(const std::string& words)
{
    if(words_map_.count(words)>0){
        words_map_[words]=words_map_[words]+1;
    }
    else{
        words_map_[words]=1;
        words_index_[words_index_.size()]=words;

    }
    return true;
}

std::string  ReverseIndex::get_tokens(const string& words)
{
    if(words_map_.count(words) == 0){
        return "null";
    }
    size_t index = words_map_[words];
    return words_index_[index];
}
