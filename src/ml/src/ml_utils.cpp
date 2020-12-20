#include <vector>
#include <map>
#include <string>

#include "ml_utils.h"

namespace hats {

    template <typename T>
    MapStoVi oneHotEncode(std::vector<T> &data) {
        MapStoVi labelMap;
        for (int i = 0; i < uniqueLabels.size(); i++) {
            std::vector<int> ohv(uniqueLabels.size(), 0);
            ohv[i] = 1;
            
            labelMap.insert({uniqueLabels[i], ohv});
        }

        return labelMap;
    }



}