#ifndef WORD_VECTOTS_REVERSE_INDEX_H
#define WORD_VECTOTS_REVERSE_INDEX_H
#include <string>
#include <vector>
#include <map>
using namespace std;
class ReverseIndex{
    public:
        ReverseIndex();
        ~ReverseIndex();
        bool insert(const string& words);
        string get_tokens(const string& word);
    private:
        map<string,int> words_map_;
        map<int,string>  words_index_;
};
#endif //WORD_VECTOTS_REVERSE_INDEX_H
