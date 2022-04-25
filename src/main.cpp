#include <iostream>
#include "./include/helpers.h"
#include "./include/labels.h"

using namespace std;

int main() {

    cout << OS_LABEL << getOS() << endl;
    cout << HOST_LABEL << getHost() << endl;
    cout << KERNEL_LABEL << "fuck u" << endl;
    cout << UPTIME_LABEL << "fuck u" << endl;
    cout << PACKAGES_LABEL << "fuck u" << endl;

    return 0;
}