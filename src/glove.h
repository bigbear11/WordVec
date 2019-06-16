#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

#define _FILE_OFFSET_BITS 64
#define MAX_STRING_LENGTH 1000
typedef struct cooccur_rec {
    int word1;
    int word2;
    real val;
} CREC
class Glove{
    public:
        Glove();
        ~Glove();
        void train_glove();
    private:
        char* vocab_file;
        char* input_file;
};
