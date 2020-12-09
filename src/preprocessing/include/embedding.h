#pragma once
#ifndef EMBEDDING_H
#define EMBEDDING_H

#include "Fasttext.h"

namespace hats {

    class Embedding {
        public:
            std::shared_ptr<fasttext::FastText> ftFasttext;
            fasttext::Args ftArgs;

            Embedding(std::string filename) {
                ftArgs = fasttext::Args();
                ftFasttext = std::make_shared<fasttext::FastText>();
                ftArgs.input = filename;
            }
            
            ~Embedding() {}

            void train();
    
            // fasttext::FastText getWordEmbedding(std::string word);

            // FloatList getSentenceEmbedding(std::string sentence);
    };
}

#endif // !EMBEDDING_H