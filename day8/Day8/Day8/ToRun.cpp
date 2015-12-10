#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    stringList = vector<string>();
    getInput();
}


ToRun::~ToRun()
{
}


void ToRun::getInput(){
    string line;
    ifstream myfile("Text.txt");
    int bigCount = 0;
    int smallCount = 0;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            stringList.push_back(line);
            IntPair stringCount = getEncodedCharacterCount(line);
            bigCount += stringCount.first;
            smallCount += stringCount.second;
        }
        myfile.close();
        int finalNum = bigCount - smallCount;
        finalNum += 0;
    }
}

IntPair ToRun::getCharacterCount(string line){
    IntPair toReturn;
    int iter = 1;
    while (iter < line.length()-1){
        char curChar = line.at(iter);
        if (curChar == '\\'){
            char secondchar = line.at(iter + 1);
            if (secondchar == '\\'){
                toReturn.first += 2;
                toReturn.second += 1;
                iter += 2;
            }
            else if (secondchar == '\"'){
                toReturn.first += 2;
                toReturn.second += 1;
                iter += 2;
            }
            else if (secondchar == 'x'){
                toReturn.first += 4;
                toReturn.second += 1;
                iter += 4;
            }
        }
        else{
            toReturn.first ++;
            toReturn.second ++;
            iter++;
        }
    }
    return toReturn;
}

IntPair ToRun::getEncodedCharacterCount(string line){
    IntPair toReturn;
    int iter = 1;
    while (iter < line.length() - 1){
        char curChar = line.at(iter);
        if (curChar == '\\'){
            char secondchar = line.at(iter + 1);
            if (secondchar == '\\'){
                toReturn.first += 4;
                toReturn.second += 2;
                iter += 2;
            }
            else if (secondchar == '\"'){
                toReturn.first += 4;
                toReturn.second += 2;
                iter += 2;
            }
            else if (secondchar == 'x'){
                toReturn.first += 5;
                toReturn.second += 4;
                iter += 4;
            }
        }
        else{
            toReturn.first++;
            toReturn.second++;
            iter++;
        }
    }
    return toReturn;
}