#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    string line = "cqjxjnds";
    while (!includesStraight(line) || !includesTwoPair(line) || !noBadLetters(line)){
        line = getNextString(line);
    }
    line = getNextString(line);
    while (!includesStraight(line) || !includesTwoPair(line) || !noBadLetters(line)){
        line = getNextString(line);
    }
    string result = line;
}


ToRun::~ToRun()
{
}


bool ToRun::includesStraight(string line){
    for (int i = 0; i < line.length() - 2; i++){
        if (line.at(i + 1) - line.at(i) == 1 && line.at(i + 2) - line.at(i + 1) == 1){
            return true;
        }
    }
       return false;
}

bool ToRun::includesTwoPair(string line){
    int pairCount = 0;
    int iter = 0;
    vector<char> pairedChar= vector<char>();
    while (iter < line.length() - 1){
        if (line.at(iter) == line.at(iter + 1)){
            if (std::find(pairedChar.begin(), pairedChar.end(), line.at(iter)) == pairedChar.end()) {
                pairCount ++;
                pairedChar.push_back(line.at(iter));
                iter += 2;
            }
            else {
                iter++;
            }
        }
        else{
            iter++;
        }
    }
    if (pairCount >= 2){
        pairCount += 0;
    }
    return pairCount>=2;
}

bool ToRun::noBadLetters(string line){
    for (int i = 0; i < line.length(); i++){
        char testChar = line.at(i);
        if (testChar == 'i' || testChar == 'o' || testChar == 'l'){
            return false;
        }
    }
     return true;
}

string ToRun::getNextString(string line){
    bool successIncrement = false;
    int curIndex = line.length() - 1;
    while (!successIncrement){
        if (curIndex < 0){
            break;
        }
        if (line.at(curIndex) == 'z'){
            line.replace(curIndex, 1, "a");
            curIndex--;
        }
        else{
            char curIndexChar = line.at(curIndex);
            curIndexChar++;
            stringstream ss;
            string charString;
            ss << curIndexChar;
            ss >> charString;
            line.replace(curIndex, 1, charString);
            successIncrement = true;
        }
    }
    return line;
}