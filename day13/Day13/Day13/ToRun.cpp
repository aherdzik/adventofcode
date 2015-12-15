#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    maxCount = 0;
    inputData();
    runProgram();
}


ToRun::~ToRun()
{
}

void ToRun::inputData(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            currentData[j][i] = 0;
        }
    }

    currentData[0][1] = 54;
    currentData[0][2] = -81;
    currentData[0][3] = -42;
    currentData[0][4] =  89;
    currentData[0][5] = -89;
    currentData[0][6] = 97;
    currentData[0][7] = -94;
    currentData[0][8] = 0;


    currentData[1][0] = 3;
    currentData[1][2] = -70;
    currentData[1][3] = -31;
    currentData[1][4] = 72;
    currentData[1][5] = -25;
    currentData[1][6] = -95;
    currentData[1][7] = 11;
    currentData[1][8] = 0;

    currentData[2][0] = -83;
    currentData[2][1] = 8;
    currentData[2][3] = 35;
    currentData[2][4] = 10;
    currentData[2][5] = 61;
    currentData[2][6] = 10;
    currentData[2][7] = 29;
    currentData[2][8] = 0;

    currentData[3][0] = 67;
    currentData[3][1] = 25;
    currentData[3][2] = 48;
    currentData[3][4] = -65;
    currentData[3][5] = 8;
    currentData[3][6] = 84;
    currentData[3][7] = 9;
    currentData[3][8] = 0;

    currentData[4][0] = -51;
    currentData[4][1] = -39;
    currentData[4][2] = 84;
    currentData[4][3] = -98;
    currentData[4][5] = -20;
    currentData[4][6] = -6;
    currentData[4][7] = 60;
    currentData[4][8] = 0;

    currentData[5][0] = 51;
    currentData[5][1] = 79;
    currentData[5][2] = 88;
    currentData[5][3] = 33;
    currentData[5][4] = 43;
    currentData[5][6] = 77;
    currentData[5][7] = -3;
    currentData[5][8] = 0;

    currentData[6][0] = -14;
    currentData[6][1] = -12;
    currentData[6][2] = -52;
    currentData[6][3] = 14;
    currentData[6][4] = -62;
    currentData[6][5] = -18;
    currentData[6][7] = -17;
    currentData[6][8] = 0;

    currentData[7][0] = -36;
    currentData[7][1] = 76;
    currentData[7][2] = -34;
    currentData[7][3] = 37;
    currentData[7][4] = 40;
    currentData[7][5] = 18;
    currentData[7][6] = 7;
    currentData[7][8] = 0;

    currentData[8][0] = 0;
    currentData[8][1] = 0;
    currentData[8][2] = 0;
    currentData[8][3] = 0;
    currentData[8][4] = 0;
    currentData[8][5] = 0;
    currentData[8][6] = 0;
    currentData[8][7] = 0;
}

void ToRun::runProgram(){
    int maxNum = 0;
    vector<int> fullVector = vector<int>();
    for (int i = 0; i < 9; i++){
        fullVector.push_back(i);
    }
    for (int i = 0; i < 9; i++){
        vector<int> baseVector = vector<int>();
        baseVector.push_back(i);
        vector<int> newVector = fullVector;
        newVector.erase(newVector.begin() + i);

        int result = bestCombined(baseVector, newVector);
        if (result > maxNum){
            maxNum = result;
        }

    }
    maxNum += 0;
    maxCount += 0;
}

int ToRun::bestCombined(vector<int> prefix, vector<int> post){
    int toReturn = 0;

    if (prefix.size() == 9){
        return evalCombination(prefix);
    }
    
    for (int i = 0; i < post.size(); i++){
        vector<int> newVector = prefix;
        vector<int> postVector = post;
        newVector.push_back(postVector.at(i));
        postVector.erase(postVector.begin() + i);
        int result = bestCombined(newVector, postVector);
        if (result > toReturn){
            toReturn = result;
        }
    }
    return toReturn;
}

int ToRun::evalCombination(vector<int> combination){
    int toReturn = 0;
    for (int i = 0; i < combination.size()-1; i++){
        int first = combination.at(i);
        int second = combination.at(i+1);
        toReturn += currentData[first][second];
        toReturn += currentData[second][first];
    }
    int last = combination.size() - 1;
    toReturn += currentData[last][0];
    toReturn += currentData[0][last];
    if (maxCount < toReturn){
        maxCount = toReturn;
    }
    return toReturn;
}
