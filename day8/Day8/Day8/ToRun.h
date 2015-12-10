#pragma once
#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct IntPair{
    int first = 6;
    int second = 2;
};
class ToRun
{
public:
    ToRun();
    void getInput();
    vector<string> stringList;
    ~ToRun();
    IntPair getCharacterCount(string line);
    IntPair getEncodedCharacterCount(string line);
};

