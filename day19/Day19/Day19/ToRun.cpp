#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    readInInput();
    runProgram();
}


ToRun::~ToRun()
{
}


void ToRun::readInInput(){
    string line;
    ifstream myfile("Text.txt");
    if (myfile.is_open())
    {
        int iter = 0;
        while (getline(myfile, line))
        {
            if (iter == 0){
                startingString = line;
            }
            else{
                vector<string> splitString = split(line, ' ');
                availableIterations.push_back(ChemIteration(splitString.at(0), splitString.at(2)));
            }

            iter++;
        }
        myfile.close();
    }
}

std::vector<std::string> ToRun::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> ToRun::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

void ToRun::runProgram(){
    int turnCount = 0;
    while (startingString.compare("e")!=0){
        turnCount++;
        int stringCount = 0;
        for (ChemIteration chem : availableIterations){
            stringCount+=compactString(chem);
        }
    }

    int test = turnCount;
    test += 0;
}

int ToRun::addIterations(ChemIteration chem,string baseString){
    int iterNum = baseString.length() - chem.start.length();
    int stringCount = 0;
    for (int i = 0; i <= iterNum; i++){
        if (baseString.compare(i, chem.start.length(), chem.start) == 0){
            string newString = baseString;
            newString.replace(i, chem.start.length(), chem.end);
            bool foundMatch = false;
            for (string curString : usedStrings){
                if (curString.compare(newString) == 0){
                    foundMatch = true;
                    break;
                }
            }

            if (!foundMatch){
                usedStrings.push_back(newString);
                stringCount++;
            }
        }
    }
    return stringCount;
}

int ToRun::compactString(ChemIteration chem){
    int iterNum = startingString.length() - chem.end.length();
    int stringCount = 0;
    for (int i = 0; i <=iterNum; i++){
        if (startingString.compare(i, chem.end.length(), chem.end) == 0){
            startingString.replace(i, chem.end.length(), chem.start);
            stringCount++;
            iterNum = startingString.length() - chem.end.length();
            return stringCount;
        }
    }
    return stringCount;
}