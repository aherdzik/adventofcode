#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    inputVector = vector<string>();
    fillDataHolder();
    runProgram();
}


ToRun::~ToRun()
{
    
}

void ToRun::fillDataHolder(){
    ifstream myfile;
    string line = "";
    myfile.open("Text.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            inputVector.push_back(line);

        }
        myfile.close();
    }
}

void ToRun::runProgram(){
    int niceCount = 0;
    for (string s : inputVector){
        if (hasTwoPair(s) && hasDoubleLetter(s))
            niceCount++;
    }
    niceCount += 0;
}

bool ToRun::hasTwoPair(string input){
    for (int i = 0; i < input.length()-3; i++){
        string toFind = input.substr(i, 2);
        string remainder = input.substr(i + 2);
        if (remainder.find(toFind) != string::npos)
            return true;
    }
    return false;
}

bool ToRun::hasDoubleLetter(string input){
    for (int i = 0; i < input.length()-2; i++){
        if (input.at(i) == input.at(i + 2))
            return true;
    }
    return false;
}

bool ToRun::noContainSpecialString(string input){
    return (input.find("ab") == string::npos) && (input.find("cd") == string::npos) && (input.find("pq") == string::npos) && (input.find("xy") == string::npos);
}