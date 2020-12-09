#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "pre_utils.h"
#include "embedding.h"

namespace hats {
    void Embedding::train()
    {
        ftFasttext->train(ftArgs);
        ftFasttext->saveModel("model.h");
        ftFasttext->saveVectors("embeddings.vec");
    }

    // fasttext::FastText Embedding::getWordEmbedding(std::string word)
    // {
    //     // ftFasttext.getWordVector();
    //     return 0;
    // }

    // FloatList Embedding::getSentenceEmbedding(std::string sentence)
    // {
    //     return NULL;
    // }
}