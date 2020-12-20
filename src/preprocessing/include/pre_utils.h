#pragma once
#ifndef PRE_UTILS_H
#define PRE_UTILS_H

#include <vector>
#include <string>
#include <utility>

#include "vector.h"

namespace hats {
    typedef std::vector<std::string> StringList;
	typedef std::pair<std::string, std::vector<std::string>> DataColumn;
	typedef std::vector<DataColumn> DataTable;
    typedef std::vector<float> FloatList;

    typedef fasttext::Vector FasttextVector;
	typedef std::pair<std::string, std::vector<FasttextVector>> FasttextDataColumn;
	typedef std::vector<FasttextDataColumn> FasttextVectorData;
    typedef std::vector<std::vector<int>> LabelList;

    struct FasttextDataTable {
        FasttextVectorData ftVectorData;
        LabelList labelList;
    };
}

#endif // !PRE_UTILS_H