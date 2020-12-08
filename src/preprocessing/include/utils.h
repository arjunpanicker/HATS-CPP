#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>

namespace hats {
    typedef std::vector<std::string> StringList;
	typedef std::pair<std::string, std::vector<std::string>> DataColumn;
	typedef std::vector<DataColumn> DataTable;
    typedef std::vector<float> FloatList;
}

#endif // !UTILS_H