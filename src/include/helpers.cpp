#include "./helpers.h"
#include "./stringManip.h"
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

std::string getOS() {
    std::string str, seg, os;
    
    std::ifstream readStream("/etc/os-release"); // Open /etc/os-version
    getline(readStream, str);                    // Read first line and put it in str
    readStream.close();                          // Close /etc/os-version

    os = stringSplit(str, '"').at(1);            // Split str with '"' separator, then take the second element

    return os;
}

std::string getHost() {
    std::string hostname;

    std::ifstream readStream("/etc/hostname");
    getline(readStream, hostname);
    readStream.close();

    return hostname;
}