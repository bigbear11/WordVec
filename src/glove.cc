#include "glove.h"

using namespace std;

Glove::Glove(){

}
Glove::~Glove(){

}
void Glove::train_glove(){
    long a, b ,l1, l2;
    CREC res;
    real diff, fdiff, temp1, temp2;
    FILE *fin;
    fin = fopen(input_file, "rb");
    cost[id] = 0;
    real* W_updates1 = (real*)malloc(vector_size * sizeof(real));
    real* W_updates2 = (real*)malloc(vector_size * sizeof(real));
    for (a = 0; a < lines_per_thread[id]; a++) {
        fread(&res, sizeof(CREC), 1, fin);
        if (feof(fin)) break;
        if (res.word1 < 1 || res.word2 < 1) { continue; }
        l1 = (res.word1 - 1LL) * (vector_size + 1);
        l2 = ((res.word2 - 1LL) + vocab_size) * (vector_size + 1);
        
        diff = 0;
        for (b = 0; b < vector_size; b++) diff += W[b + l1] * W[b + l2];
        diff += W[vector_size + l1] + W[vector_size + l2] - log(res.val);
        fdiff = (res.val > x_max) ? diff : pow(res.val / x_max, alpha) * diff;


        cost[id] += 0.5 * fdiff * diff;
        
        fdiff *= eta;
        real W_updates1_sum = 0;
        real W_updates2_sum = 0;
        for (b = 0; b < vector_size; b++) {
            temp1 = fdiff * W[b + l2];
            temp2 = fdiff * W[b + l1];
            W_updates1[b] = temp1 / sqrt(gradsq[b + l1]);
            W_updates2[b] = temp2 / sqrt(gradsq[b + l2]);
            W_updates1_sum += W_updates1[b];
            W_updates2_sum += W_updates2[b];
            gradsq[b + l1] += temp1 * temp1;
            gradsq[b + l2] += temp2 * temp2;
        }
        if (!isnan(W_updates1_sum) && !isinf(W_updates1_sum) && !isnan(W_updates2_sum) && !isinf(W_updates2_sum)) {
            for (b = 0; b < vector_size; b++) {
                W[b + l1] -= W_updates1[b];
                W[b + l2] -= W_updates2[b];
            }
        }

        W[vector_size + l1] -= check_nan(fdiff / sqrt(gradsq[vector_size + l1]));
        W[vector_size + l2] -= check_nan(fdiff / sqrt(gradsq[vector_size + l2]));
        fdiff *= fdiff;
        gradsq[vector_size + l1] += fdiff;
        gradsq[vector_size + l2] += fdiff;
        
    }
    free(W_updates1);
    free(W_updates2);
    
    fclose(fin);
}

int scmp( char *s1, char *s2 ) {
    while (*s1 != '\0' && *s1 == *s2) {s1++; s2++;}
    return(*s1 - *s2);
}
