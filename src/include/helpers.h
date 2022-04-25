#pragma once
#include <iostream>

std::string getOS();    // Reads os version from /etc/os-release and returns a string in the format PRETTY_NAME="{os}"

std::string getHost();  // Reads hostname from /etc/hostname