#pragma once
#include <iostream>
#include <vector>

std::string getOS();                     // Gets os version from /etc/os-release and returns a string in the format PRETTY_NAME="{os}"

std::string getHost();                   // Gets host machine

std::string getHostName();               // Gets hostname from /etc/hostname

std::string getUser();                   // Gets user using getlogin(), pretty useless tbh

std::string getKernel();                 // Gets kernel using uname()

std::vector<std::string> getUptime();    // Gets uptime from sysinfo, divides it into days, hours, minutes and seconds, then converts it to std::string and puts it in a vector

std::string getCPUmodel();                    // Gets CPU model