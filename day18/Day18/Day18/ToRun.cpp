#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    readInInput();
    runSim();
    countLights();
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
            for (int i = 0; i < line.length(); i++){
                char curChar = line.at(i);
                if (curChar == '#'){
                    currentData[iter][i] = true;
                }
                else if (curChar == '.'){
                    currentData[iter][i] = false;
                }
            }
            iter++;
        }
        myfile.close();
    }
}

void ToRun::runSim(){
    for (int i = 0; i < 100; i++){
        runIteration();
    }
}

void ToRun::countLights(){
    int count = 0;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (currentData[i][j]){
                count++;
            }
        }
    }
    count += 0;
}

void ToRun::runIteration(){
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (!((i == 0 && j == 0) || (i == 0 && j == 99) || (i == 99 && j == 0) || (i == 99 && j == 99))){
                if (currentData[i][j]){
                    if (countNeighbors(i, j) == 2 || countNeighbors(i, j) == 3){
                        newData[i][j] = true;
                    }
                    else{
                        newData[i][j] = false;
                    }
                }
                else{
                    if (countNeighbors(i, j) == 3){
                        newData[i][j] = true;
                    }
                    else{
                        newData[i][j] = false;
                    }
                }
            }

        }
    }
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            currentData[i][j] = newData[i][j];
        }
    }
}

int ToRun::countNeighbors(int l, int w){
    int neighborCount = 0;
    if (l != 0){
        if (w != 0){
            if (currentData[l - 1][w - 1])
                neighborCount++;
        }
        if (currentData[l - 1][w])
            neighborCount++;
        if (w != 99){
            if (currentData[l - 1][w + 1])
                neighborCount++;
        }
    }
    if (w != 0){
        if (currentData[l][w - 1])
            neighborCount++;
    }
    if (w != 99){
        if (currentData[l][w + 1])
             neighborCount++;
    }
    if (l != 99){
        if (w != 0){
            if (currentData[l+1][w - 1])
                neighborCount++;
        }
        if (currentData[l + 1][w])
            neighborCount++;
        if (w != 99){
            if (currentData[l + 1][w + 1])
                neighborCount++;
        }
    }
    return neighborCount;
}