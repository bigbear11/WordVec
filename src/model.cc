#include <fstream>
#include <time.h> 

#include"model.h"

using namespace std;
TrainModel::TrainModel(){

}

TrainModel::~TrainModel(){

}

bool TrainModel::Init(const std::string trainfile){
    train_file_=trainfile;
    return true;

}

float TrainModel::Sigmoid(const float& x){
   return (1 / (1 + exp(-x))); 
}
void TrainModel::Train(const std::vector<VocabWords>& vocab_words,const std::map<std::string,int> word_hash) {
    std::ifstream in(train_file_.c_str());
    if(!in.is_open()){
        cout << "open file " <<train_file_<<" failed"<<endl;
        return;
    }
    int window=2;
    int vocab_size=vocab_words.size();
    std::vector<std::vector<float> >vec0;
    std::vector<std::vector<float> >vec1;
    for(int i=0;i< vocab_size;i++)
        for(int j=0;j< dim;j++){
            vec0[i][j]=rand();
            vec1[i][j]=rand();
        }
    std::string line;
    while(getline(in,line)){
        std::vector<std::string> items;
        split(items,line,boost::is_any_of(" "));
        sentence_position=0;
        while(sentence_position< items.size()){
            std::vector<float> w(dim,0);
            std::vector<float> neu(dim,0);
            int loc;
            float g,f;
            if((sentence_position<window)||(sentence_position+window)>items.size-1){
                sentence_position++;
                continue;
            }
            for(int cw=sentence_position-2;cw<sentence_position+2;cw++){
                if(cw==sentence_position) continue;
                int nu=word_hash[items[cw]];
                VecAdd(vec0[nu],w);
            }
            VocabWords loc_word=vocab_words[word_hash[sentence_position]];
            for(int d=0;d<loc_word.point.size();d++){
                loc=loc_word.point[d];
                for (int a = 0; a < dim; a++) f=w[a]*vec1[loc][a];
                g = (1 - loc_word.code[d] - f) * alpha;
                for (int b = 0; b < dim; b++) neu[c] += g * v1[loc][b];
                for (int c = 0; c < dim; c++) vec1[loc][c] += g * w[c];
            }

            for(int cw=sentence_position-2;cw<sentence_position+2;cw++){
                if(cw==sentence_position) continue;
                int nu=word_hash[items[cw]];
                VecAdd(neu,vec0[nu]);
            }
            sentence_position++;

        }
         
    }
}
void TrainModel::VecAdd(const std::vector<float>& v1,std::vector<float>& v2){
    for(int i=0;i<v2.size();i++){
        v2[i]=v1[i]+v2[i];
    
    }
}
