#include "./helpers.h"
#include "./stringManip.h"
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

#include <unistd.h>

#include <sys/utsname.h>

std::string getOS() {
    std::string str, os;
    
    std::ifstream readStream("/etc/os-release"); // Open /etc/os-version
    getline(readStream, str);                    // Read first line and put it in str
    readStream.close();                          // Close /etc/os-version

    os = stringSplit(str, '"').at(1);            // Split str with '"' separator, then take the second element

    return os;
}

std::string getHostName() {
    std::string hostname;

    std::ifstream readStream("/etc/hostname"); // Open /etc/hostname
    getline(readStream, hostname);             // Read first line and put it in hostname
    readStream.close();                        // Close /etc/hostname

    return hostname;
}

std::string getUser() {
    std::string user = getlogin();  // I could just call getlogin() directly in main.cpp but **I'm a material gurl**

    return user;
}

std::string getKernel() {
    utsname info;
    uname(&info);

    return info.release;
}