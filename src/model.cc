#include"model.h"


TrainModel::TrainModel(){

}

TrainModel::~TrainModel{

}

bool DoConfig(const std::string trainfile){
    trainfile_=trainfile.c_str();
    return true;

}

float TrainModel::sigmoid(const float& x){
   return (1 / (1 + exp(-x))); 
}
void TrainModel::train() {
    int  a, b, d, cw, word, 
    int  last_word, sentence_length = 0, sentence_position = 0;
    int  word_count = 0, last_word_count = 0, sen[5000];
    int  l1, l2, c;
    float f, g;
    float *w1 = (float *)calloc(dim, sizeof(float));
    float *w2 = (float *)calloc(dim, sizeof(float));
    FILE *fi = fopen(train_file_, "rb");
    while (1) {
        if (sentence_length == 0) {
        while (1) {
            word = ReadWordIndex(fi);
            if (feof(fi)) break;
            if (word == -1) continue;
            word_count++;
            if (word == 0) break;
            sen[sentence_length] = word;
            sentence_length++;
            if (sentence_length >= MAX_SENTENCE_LENGTH) break;
        }
        sentence_position = 0;
    }
    word = sen[sentence_position];
    if (word == -1) continue;
    for (c = 0; c < dim; c++) w1[c] = 0;
    for (c = 0; c < dim; c++) neu1e[c] = 0;
    if (cbow) { 
        cw = 0;
        for (a = b; a < window * 2 + 1 - b; a++) if (a != window) {
        c = sentence_position - window + a;
        if (c < 0) continue;
        if (c >= sentence_length) continue;
        last_word = sen[c];
        if (last_word == -1) continue;
        for (c = 0; c < dim; c++) w1[c] += syn0[c + last_word * dim];
        cw++;
      }
        if (cw) {
            for (c = 0; c < dim; c++) w1[c] /= cw;
            f = 0;
            l2 = vocab[word].point[d] * dim;
            for (c = 0; c < dim; c++) f += w1[c] * syn1[c + l2];
            g = (1 - vocab[word].code[d] - f) * alpha;
            for (c = 0; c < dim; c++) neu1e[c] += g * syn1[c + l2];
            for (c = 0; c < dim; c++) syn1[c + l2] += g * w1[c];
        }
        for (a = b; a < window * 2 + 1 - b; a++) if (a != window) {
          c = sentence_position - window + a;
            if (c < 0) continue;
            if (c >= sentence_length) continue;
            last_word = sen[c];
            if (last_word == -1) continue;
            for (c = 0; c < dim; c++) syn0[c + last_word * dim] += w2[c];
         }
    }
    sentence_position++;
    if (sentence_position >= sentence_length) {
        sentence_length = 0;
        continue;
    }
  }
}

