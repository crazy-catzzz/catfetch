#include "../include/fileManip.h"
#include <limits>

std::ifstream& gotoLine_r(std::ifstream &file, int line) {
    file.seekg(std::ios::beg);
    for (int i = 0; i < line; i++) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}

std::fstream& gotoLine_rw(std::fstream &file, int line) {
    file.seekg(std::ios::beg);
    for (int i = 0; i < line; i++) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
};