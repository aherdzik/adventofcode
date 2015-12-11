#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma once
class ToRun
{
public:
    ToRun();
    ~ToRun();
    bool includesStraight(string line);
    bool includesTwoPair(string line);
    bool noBadLetters(string line);
    string getNextString(string line);
};

