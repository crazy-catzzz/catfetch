#include <iostream>
#include "./include/helpers.h"
#include "./include/labels.h"

using namespace std;

int main() {

    cout << OS_LABEL << getOS() << endl;
    cout << HOST_LABEL << getHost() << endl;

    return 0;
}