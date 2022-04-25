#pragma once
#include <iostream>
#include <fstream>

std::ifstream& gotoLine_r(std::ifstream &file, int line);

std::fstream& gotoLine_rw(std::fstream &file, int line);