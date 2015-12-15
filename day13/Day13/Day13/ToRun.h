
#include <vector>
#pragma once
using namespace std;
class ToRun
{
public:
    ToRun();
    int currentData[9][9];
    void inputData();
    void runProgram();
    int bestCombined(vector<int> prefix, vector<int> post);
    int evalCombination(vector<int> toCombine);
    int maxCount;
    ~ToRun();
};

