#pragma once
// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class ToRun
{
public:
    void readInInput();
    bool currentData[100][100];
    bool newData[100][100];
    void runSim();
    void runIteration();
    void countLights();
    int countNeighbors(int l, int w);
    ToRun();
    ~ToRun();
};

