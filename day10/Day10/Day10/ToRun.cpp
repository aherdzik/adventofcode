#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    string testInput = "1113122113";
    for (int i = 0; i < 50; i++){
        testInput = nextIteration(testInput);
    }
    int test = testInput.length();
}

string ToRun::nextIteration(string testInput){
    int curIter = 0;
    stringstream newString;
    while (curIter < testInput.length()){
        char curChar = testInput.at(curIter);
        int testIter = 1;
        while ((curIter +testIter)<testInput.length() && testInput.at(curIter + testIter) == curChar){
            testIter++;
        }
        newString << testIter;
        newString << curChar;
        curIter += testIter;

    }

    return newString.str();
}


ToRun::~ToRun()
{
}
