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

std::vector<int> getUptime() {
    std::vector<int> uptime;
    struct sysinfo info;
    sysinfo(&info);

    long uptimeSecs = info.uptime; // Total uptime in seconds
    int days = uptimeSecs/86400;
    int hours = uptimeSecs/3600 - days*24;
    int minutes = uptimeSecs/60 - hours*60 - days*1440;
    int seconds = uptimeSecs - minutes*60 - hours*3600 - days*86400;

    // Add uptime to vector
    uptime.push_back(days);
    uptime.push_back(hours);
    uptime.push_back(minutes);
    uptime.push_back(seconds);

    return uptime;
}

std::string getCPUmodel() {
    std::stringstream sstream;
    std::string model;
    std::vector<std::string> split;

    std::ifstream readStream("/proc/cpuinfo");  // Open /proc/cpuinfo
    gotoLine_r(readStream, 4);                  // Go to line 4 in /proc/cpuinfo
    std::getline(readStream, model);            // Get current line and put it in model
    readStream.close();                         // Close /proc/cpuinfo

    split = stringSplit(model, ':');
    model = split.at(1);

    return model;
}

std::vector<long> getRAMinfo() {
    std::vector<long> raminfo;
    unsigned long free;
    unsigned long used;
    unsigned long total;

    std::ifstream readStream("/proc/meminfo");
    std::string token;
    while (readStream >> token) {
        if (token == "MemTotal:")
            readStream >> total;
        
        if (token == "MemAvailable:")
            readStream >> free;
    }

    used = total - free;

    raminfo.push_back(total/1024);
    raminfo.push_back(used/1024);

    return raminfo;
}