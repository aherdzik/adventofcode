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
public:
    ToRun();
    void fillDataHolder();
    void runProgram();
    ~ToRun();
    vector<string> inputVector;

    bool hasTwoPair(string input);
    bool hasDoubleLetter(string input);
    bool noContainSpecialString(string input);
};

