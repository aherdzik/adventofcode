#pragma once

#include <vector>
#include <algorithm>
using namespace std;
class ToRun
{
public:
    void readInData();
    ToRun();
    int dataInput[20];
    void runProgram();
    int evalCombination(bool input[20]);
    ~ToRun();
};

