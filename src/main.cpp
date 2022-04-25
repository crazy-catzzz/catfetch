#include <iostream>
#include "./include/helpers.h"
#include "./include/labels.h"

using namespace std;

int main(int argc, char **argv) {

    cout << OS_LABEL << getOS() << endl;
    cout << HOSTNAME_LABEL << getHostName() << endl;
    cout << HOST_LABEL << "fuck u" << endl;
    cout << KERNEL_LABEL << getKernel() << endl;
    cout << UPTIME_LABEL << "fuck u" << endl;
    cout << PACKAGES_LABEL << "fuck u" << endl;

    return 0;
}