#include "./stringManip.h"
#include <sstream>

std::vector<std::string> stringSplit(std::string toSplit, char separator) {
    std::string seg;
    std::stringstream sstream(toSplit);
    std::vector<std::string> split;

    while(std::getline(sstream, seg, separator)) {
        split.push_back(seg);
    }

    return split;
}