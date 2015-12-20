#pragma once
// reading a text file
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct ChemIteration{
    string start;
    string end; 
    ChemIteration(string newStart, string newEnd) : start(newStart), end(newEnd)
    {
    }
};
class ToRun
{
public:
    ToRun();
    string startingString;

    vector<string> usedStrings;
    std::vector<std::string> split(const std::string &s, char delim);
    std::vector<std::string> split(const std::string &s, char delim, std::vector<std::string> &elems);
    void readInInput();
    void findIterations();
    void runProgram();
    int addIterations(ChemIteration chem, string testString);
    int compactString(ChemIteration chem);
    vector<ChemIteration> availableIterations;

    ~ToRun();
};

