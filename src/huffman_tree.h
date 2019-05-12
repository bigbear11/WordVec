#include"type.h"

class HuffmanTree{
public:
    HuffmanTree();
    ~HuffmanTree();

public:
    void GetCode(std::vector<VocabWord>& vocab);

private:
    bool CreateBinaryTree(const std::vector<VocabWord> vocab);

private:
    std::vector<long long> count_;
    std::vector<long long> binary_side_;
    std::vector<long long> parent_node_;
    long long point_;


};
