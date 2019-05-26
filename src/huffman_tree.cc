#include"huffman_tree.h"


HuffmanTree::HuffmanTree(){

}
HuffmanTree::~HuffmanTree(){

}

void HuffmanTree::GetCode(std::vector<VocabWords>& vocab_words){ 
    int vocab_size=vocab_words.size();
    std::vector<int> count;
    std::vector<int> code(vocab_size,0),point(vocab_size,0);
    int i;
    for(int idx=0;idx<vocab_size;idx++){
        count.push_back(vocab_words[idx].cn);
    }
    for(int a;a<2*vocab_size;a++){
        count.push_back(100000);
    }
    CreateBinaryTree(vocab_size,count);
    // assign code
    int a,b;
    for (a = 0; a < vocab_size; a++) {
    vocab_words[a].code=code;
    vocab_words[a].point=point;
    b = a;
    i = 0;
    while (1) {
      code[i] = binary_side_[b];
      point[i] = b;
      i++;
      b = parent_node_[b];
      if (b == vocab_size * 2 - 2) break;
    }
    vocab_words[a].codelen = i;
    vocab_words[a].point[0] = vocab_size - 2;
    for (b = 0; b < i; b++) {
      vocab_words[a].code[i - b - 1] = code[b];
      vocab_words[a].point[i - b] = point[b] - vocab_size;
    }
  }
     
}
void HuffmanTree::CreateBinaryTree(const int& vocab_size,std::vector<int>& count) {
  int a;
  int min1i, min2i;
  int pos1, pos2;

  pos1 = vocab_size - 1;
  pos2 = vocab_size;
  for(int idx=0;idx<=2*vocab_size;idx++){
      parent_node_.push_back(0);
      binary_side_.push_back(0);

  }
  // creat tree
  for (a = 0; a < vocab_size - 1; a++) {
    if (pos1 >= 0) {
      if (count[pos1] < count[pos2]) {
        min1i = pos1;
        pos1--;
      } else {
        min1i = pos2;
        pos2++;
      }
    } else {
      min1i = pos2;
      pos2++;
    }
    if (pos1 >= 0) {
      if (count[pos1] < count[pos2]) {
        min2i = pos1;
        pos1--;
      } else {
        min2i = pos2;
        pos2++;
      }
    } else {
      min2i = pos2;
      pos2++;
    }
    count[vocab_size + a] = count[min1i] + count[min2i];
    parent_node_[min1i] = vocab_size + a;
    parent_node_[min2i] = vocab_size + a;
    binary_side_[min2i] = 1;
    }

}
