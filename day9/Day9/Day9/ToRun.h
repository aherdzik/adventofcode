#pragma once

#include <vector>
using namespace std;
class ToRun
{
public:
    ToRun();
    ~ToRun();
    int dataInput[8][8];
    void readInInput();
    int findShortestRoute();
    int findLongestRoute();
    int findShortestRemainingRoute(int start, vector<int>destinations);
    int findLongestRemainingRoute(int start, vector<int>destinations);
};

