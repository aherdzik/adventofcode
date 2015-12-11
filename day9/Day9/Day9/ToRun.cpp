#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    readInInput();
    int result = findLongestRoute();
    result += 0;
}


ToRun::~ToRun()
{
}

void ToRun::readInInput(){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            dataInput[j][i] = 0;
        }
    }
    //Tristram Alpha Snowdin Tambi Faerun Norrath Straylight
    dataInput[1][0] = dataInput[0][1] = 34;
    dataInput[2][0] = dataInput[0][2] = 100;
    dataInput[3][0] = dataInput[0][3] = 63;
    dataInput[4][0] = dataInput[0][4] = 108;
    dataInput[5][0] = dataInput[0][5] = 111;
    dataInput[6][0] = dataInput[0][6] = 89;
    dataInput[7][0] = dataInput[0][7] = 132;

    dataInput[1][2] = dataInput[2][1] = 4;
    dataInput[1][3] = dataInput[3][1] = 79;
    dataInput[1][4] = dataInput[4][1] = 44;
    dataInput[1][5] = dataInput[5][1] = 147;
    dataInput[1][6] = dataInput[6][1] = 133;
    dataInput[1][7] = dataInput[7][1] = 74;

    dataInput[2][3] = dataInput[3][2] = 105;
    dataInput[2][4] = dataInput[4][2] = 95;
    dataInput[2][5] = dataInput[5][2] = 48;
    dataInput[2][6] = dataInput[6][2] = 88;
    dataInput[2][7] = dataInput[7][2] = 7;

    dataInput[3][4] = dataInput[4][3] = 68;
    dataInput[3][5] = dataInput[5][3] = 134;
    dataInput[3][6] = dataInput[6][3] = 107;
    dataInput[3][7] = dataInput[7][3] = 40;

    dataInput[4][5] = dataInput[5][4] = 11;
    dataInput[4][6] = dataInput[6][4] = 66;
    dataInput[4][7] = dataInput[7][4] = 144;

    dataInput[5][6] = dataInput[6][5] = 115;
    dataInput[5][7] = dataInput[7][5] = 135;

    dataInput[6][7] = dataInput[7][6] = 127;
}

int ToRun::findShortestRoute(){
    int toReturn = 999999;
    vector<int> baseVector = vector<int>();
    for (int i = 0; i < 8; i++){
        baseVector.push_back(i);
    }

    for (int j = 0; j < 8; j++){
        vector<int> newVector = baseVector;
        newVector.erase(newVector.begin() + j);
        int result = findShortestRemainingRoute(j, newVector);
        if (toReturn > result){
            toReturn = result;
        }
    }

    return toReturn;

}


int ToRun::findLongestRoute(){
    int toReturn = 1;
    vector<int> baseVector = vector<int>();
    for (int i = 0; i < 8; i++){
        baseVector.push_back(i);
    }

    for (int j = 0; j < 8; j++){
        vector<int> newVector = baseVector;
        newVector.erase(newVector.begin() + j);
        int result = findLongestRemainingRoute(j, newVector);  
        if (toReturn < result){
            toReturn = result;
        }
    }

    return toReturn;

}

int ToRun::findShortestRemainingRoute(int start, vector<int> destinations){
    int toReturn2 = 999999;

    if (destinations.size() == 1){
        int test = dataInput[start][destinations.at(0)];
        return test;
    }

    for (int i = 0; i < destinations.size(); i++){
        int curDestination = destinations.at(i);
        int result = dataInput[start][curDestination];
        vector<int> newVector = destinations;
        newVector.erase(newVector.begin() + i);
        result += findShortestRemainingRoute(curDestination, newVector);
        if (toReturn2 > result){
            toReturn2 = result;
        }
    }
    return toReturn2;
}

int ToRun::findLongestRemainingRoute(int start, vector<int> destinations){
    int toReturn2 =1;

    if (destinations.size() == 1){
        int test = dataInput[start][destinations.at(0)];
        return test;
    }

    for (int i = 0; i < destinations.size(); i++){
        int curDestination = destinations.at(i);
        int result = dataInput[start][curDestination];
        vector<int> newVector = destinations;
        newVector.erase(newVector.begin() + i);
        result += findLongestRemainingRoute(curDestination, newVector);
        if (toReturn2 < result){
            toReturn2 = result;
        }
    }
    return toReturn2;
}