#pragma once

// basic file operations
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
class ToRun
{

    struct DataHolder{
        int l = 0;
        int w = 0;
        int h = 0;
    };


public:
    ToRun();
    ~ToRun();
    vector<DataHolder> dataHolder;

    void fillDataHolder();
    std::vector<std::string> & split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> split(const std::string &s, char delim);
    int paperNeededForBox(DataHolder d);
    int paperNeededForAllBoxes();
    int ribbonNeededForBox(DataHolder d);
    int ribbonNeededForAllBoxes();
    void run();
};

