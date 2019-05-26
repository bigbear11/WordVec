#ifndef WORD_VECTOTS_TYPE_H
#define WORD_VECTOTS_TYPE_H

#include<string>
#include<map>
#include<vector>


struct VocabWords {
        int cn; // 词的出现次数
        std::vector<int> point; // 从根结点到叶子节点的路径
        std::string word; //词
        std::vector<int> code;  //Huffman编码 
        int codelen;// 编码长度
};
#endif //WORD_VECTOTS_TYPE_H
