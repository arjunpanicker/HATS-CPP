#pragma once
#ifndef ML_UTILS_H
#define ML_UTILS_H

namespace hats {

    // Neuron-Neuron connection
    class Connection;

    class Neuron;

    typedef std::vector<Neuron> Layer;
    typedef std::map<std::string, std::vector<int>> MapStoVi;

    template <typename T>
    MapStoVi oneHotEncode(std::vector<T> &data);
}


#endif // !ML_UTILS_H