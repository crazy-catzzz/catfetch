#include "./helpers.h"
#include "./stringManip.h"
#include "./fileManip.h"

#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

#include <unistd.h>

#include <sys/sysinfo.h>
#include <sys/utsname.h>

std::string getOS() {
    std::string str, os;
    
    std::ifstream readStream("/etc/os-release"); // Open /etc/os-version
    getline(readStream, str);                    // Read first line and put it in str
    readStream.close();                          // Close /etc/os-version

    os = stringSplit(str, '"').at(1);            // Split str with '"' separator, then take the second element

    return os;
}

std::string getHost() {
    std::string host;

    std::ifstream readStream("/sys/devices/virtual/dmi/id/product_name");
    std::getline(readStream, host);
    readStream.close();

    return host;
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

std::vector<std::string> getUptime() {
    std::vector<std::string> uptime;
    struct sysinfo info;
    sysinfo(&info);

    long uptimeSecs = info.uptime; // Total uptime in seconds
    int days = uptimeSecs/86400;
    int hours = uptimeSecs/3600 - days*24;
    int minutes = uptimeSecs/60 - hours*60 - days*1440;
    int seconds = uptimeSecs - minutes*60 - hours*3600 - days*86400;

    // Add uptime to vector
    uptime.push_back(std::to_string(days));
    uptime.push_back(std::to_string(hours));
    uptime.push_back(std::to_string(minutes));
    uptime.push_back(std::to_string(seconds));

    return uptime;
}

std::string getCPUmodel() {
    std::stringstream sstream;
    std::string model;
    std::vector<std::string> split;

    std::ifstream readStream("/proc/cpuinfo");
    gotoLine_r(readStream, 4);
    std::getline(readStream, model);
    readStream.close();

    split = stringSplit(model, ':');
    model = split.at(1);

    return model;
}