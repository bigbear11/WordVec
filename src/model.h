#ifndef WORD_VECTOTS_MODEL_H
#define WORD_VECTOTS_MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include"dict_manager.h"
#include"reverse_index.h"
#include"huffman_tree.h"
class TrainModel{
public:
    void Train();
    float sigmoid(const float& x);
private:
    char* train_file;
    int dim;
}
#endif //WORD_VECTOTS_MODEL_H
