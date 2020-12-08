#pragma once
#ifndef EMBEDDING_H
#define EMBEDDING_H

namespace hats {

    class Embedding {
        public:
            Embedding() {}
            
            ~Embedding() {}

            void train(DataTable data);
    
            FloatList getWordEmbedding(std::string word);

            FloatList getSentenceEmbedding(std::string sentence);
    };
}

#endif // !EMBEDDING_H