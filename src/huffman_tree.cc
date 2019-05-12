#include"huffman_tree.h"


HuffmanTree::HuffmanTree(){

}
HuffmanTree::~HuffmanTree(){

}

void HuffmanTree::GetCode(std::vector<VocabWord>& vocab){ 
  long long a,b,i;
  char* code;
  for (a = 0; a < vocab_size; a++) {
    b = a;
    i = 0;
    while (1) {
      code[i] = binary_side_[b];
      point_[i] = b;
      i++;
      b = parent_node_[b];
      if (b == vocab_size * 2 - 2) break;
    }
    vocab[a].codelen = i;
    vocab[a].point_[0] = vocab_size - 2;
    for (b = 0; b < i; b++) {
      vocab[a].code[i - b - 1] = code[b];
      vocab[a].point_[i - b] = point_[b] - vocab_size;
    }
  }
}
void HuffmanTree::CreateBinaryTree(const std::vector<VocabWord>& vocab) {
  long long a;
  long long min1i, min2i;
  long long pos1, pos2;
  long long vocab_size=vocab.size();
  for (a = 0; a < vocab_size; a++){
      count_[a] = vocab[a].cn,
      //printf("cn:%lld\n",vocab[a].cn);
      };
  for (a = vocab_size; a < vocab_size * 2; a++){ 
      count_[a] = 100000;
      }
  pos1 = vocab_size - 1;
  pos2 = vocab_size;
  // creat tree
  for (a = 0; a < vocab_size - 1; a++) {
    if (pos1 >= 0) {
      //printf("pos1:%lld pos2:%lld\n",pos1,pos2);
      if (count_[pos1] < count_[pos2]) {
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
      if (count_[pos1] < count_[pos2]) {
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
    count_[vocab_size + a] = count_[min1i] + count_[min2i];
    parent_node_[min1i] = vocab_size + a;
    parent_node_[min2i] = vocab_size + a;
    binary_side_[min2i] = 1;
    }

}
