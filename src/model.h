#ifndef WORD_VECTOTS_MODEL_H
#define WORD_VECTOTS_MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include"dict_manager.h"

class TrainModel{
public:
    TrainModel();
    ~TrainModel();
    bool Init(const std::string trainfile);
    void Train(const std::vector<VocabWords>& vocab_words,const std::string& label,const std::map<std::string,int> word_hash);
private:
    float Sigmoid(const float& x);
    void VecAdd(const std::vector<float>& v1,std::vector<float>& v2);
private:
    std::string train_file_;
    int dim=100;
    float alpha = 0.025;
};
#endif //WORD_VECTOTS_MODEL_H
