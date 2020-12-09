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

    fasttext::Vector Embedding::getWordEmbedding(std::string word)
    {
        fasttext::Vector vec(ftFasttext->getDimension());

        ftFasttext->getWordVector(vec, word);

        return vec;
    }

    // FloatList Embedding::getSentenceEmbedding(std::string sentence)
    // {
    //     return NULL;
    // }
}