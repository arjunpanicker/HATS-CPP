#pragma once
#ifndef ML_UTILS_H
#define ML_UTILS_H

#include <vector>
#include "pre_utils.h"

namespace hats {

    // Neuron-Neuron connection
    class Connection;

    class Neuron;

    typedef std::vector<Neuron> Layer;

    template <typename T>
    MapStoVi oneHotEncode(const T &data) {
        MapStoVi labelMap;
        for (int i = 0; i < data.size(); i++) {
            std::vector<int32_t> ohv(data.size(), 0);
            ohv[i] = 1;
            
            labelMap.insert({data[i].first, ohv});
        }

        return labelMap;
    }
}


#endif // !ML_UTILS_H