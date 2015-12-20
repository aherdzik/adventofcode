#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class ToRun
{

public:
    ToRun();
    int dataHolder[500][10];
    void readInData();
    int findAunt();
    std::vector<std::string> split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> split(const std::string &s, char delim);
    ~ToRun();
};

