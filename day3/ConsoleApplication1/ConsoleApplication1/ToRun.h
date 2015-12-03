#pragma once

// basic file operations
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <tuple> 
using namespace std;
class ToRun
{
    struct Point{
        int h = 0;
        int v = 0;
    };

    vector<int>orders;
    map<int, int> moves;
    int currentSantaMove = 0;
    int currentRoboSantaMove = 0;
public:
    ToRun();
    ~ToRun();
    void fillDataHolder();
    void runProgram();
    void addMove(int move);
    void addRoboMove(int move);
};

