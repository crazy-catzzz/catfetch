#pragma once
#include <iostream>

std::string getOS();        // Gets os version from /etc/os-release and returns a string in the format PRETTY_NAME="{os}"

std::string getHost();      // Gets host machine

std::string getHostName();  // Gets hostname from /etc/hostname

std::string getUser();      // Gets user using getlogin(), pretty useless tbh

std::string getKernel();    // Gets kernel using uname()