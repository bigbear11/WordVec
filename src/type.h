#include<string>
#include<map>
#include<vector>

struct VocabWord {
        long long cn; // 词的出现次数
        int *point; // 从根结点到叶子节点的路径
        std::string word, //词
        char* code,  //Huffman编码 
        char* codelen;// 编码长度
};
