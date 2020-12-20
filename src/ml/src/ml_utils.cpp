#include <vector>
#include <string>

#include "ml_utils.h"
#include "pre_utils.h"

namespace hats {

    template <typename T>
    MapStoVi oneHotEncode(std::vector<T> &data) {
        MapStoVi labelMap;
        for (int i = 0; i < data.size(); i++) {
            std::vector<int> ohv(data.size(), 0);
            ohv[i] = 1;
            
            labelMap.insert({data[i], ohv});
        }

        return labelMap;
    }



}