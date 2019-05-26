#ifndef WORD_VECTOTS_HUFFMAN_TREE__H
#define WORD_VECTOTS_HUFFMAN_TREE__H

#include"type.h"

class HuffmanTree{
public:
    HuffmanTree();
    ~HuffmanTree();

public:
    void GetCode(std::vector<VocabWords>& vocab_words);

private:
    void CreateBinaryTree(const int& vocab_size,std::vector<int>& count);

private:
    std::vector<int> binary_side_;
    std::vector<int> parent_node_;


};
#endif //WORD_VECTOTS_HUFFMAN_TREE__H
