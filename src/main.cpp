#include <iostream>
#include <vector>

#include "./include/helpers.h"
#include "./include/labels.h"

using namespace std;

int main(int argc, char **argv) {

    std::vector<int> uptime = getUptime();     /* Uptime vector
                                                * 0: Days
                                                * 1: Hours
                                                * 2: Minutes
                                                * 3: Seconds
                                                */
    
    std::vector<long> raminfo = getRAMinfo();   /* RAM info vector
                                                * 0: Total RAM
                                                * 1: Used RAM
                                                */

    cout << getUser() << '@' << getHostName() << endl; // Print a title in the format user@hostname
    for (int i = 0; i < 10; i++) cout << '-';          // Print separator
    cout << endl;

    cout << OS_LABEL << getOS() << endl;
    cout << HOST_LABEL << getHost() << endl;
    cout << KERNEL_LABEL << getKernel() << endl;
    cout << UPTIME_LABEL << uptime.at(0) << " days, " << uptime.at(1) << " hours, " << uptime.at(2) << " minutes, " << uptime.at(3) << " seconds" << endl;
    cout << PACKAGES_LABEL << "fuck u" << endl;
    cout << CPU_LABEL << getCPUmodel() << endl;
    cout << MEMORY_LABEL << raminfo.at(1) << "MiB / " << raminfo.at(0) << "MiB" << endl;

    return 0;
}