#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    orders = vector<int>();
    moves = map<int, int>();
    fillDataHolder();
    runProgram();
    
}


ToRun::~ToRun()
{
}


void ToRun::fillDataHolder()
{
    ifstream myfile;
    string line="";
    myfile.open("Text.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            for (int i = 0; i < line.length(); i++){
                char curChar = (char)line[i];
                if (curChar == '^'){
                    orders.push_back(0);
                }
                else if (curChar == '>'){
                    orders.push_back(1);
                }
                else if (curChar == 'v'){
                    orders.push_back(2);
                }
                else if (curChar == '<'){
                    orders.push_back(3);
                }
            }

        }
        myfile.close();
    }
}

void ToRun::runProgram()
{
    moves[0] = 1;
    for (int i = 0; i < orders.size(); i+=2){
        addMove(orders[i]);
        if (i != orders.size()-1){
            addRoboMove(orders[i+1]);
        }
    }

    int test = moves.size();
    test += 0;
}

void ToRun::addMove(int move)
{
    switch (move){
    case 0:
        currentSantaMove += 10000;
        break;
    case 1:
        currentSantaMove += 1;
        break;
    case 2:
        currentSantaMove -= 10000;
        break;
    case 3:
        currentSantaMove -= 1;
        break;
    }
    if (moves[currentSantaMove == NULL]){
        moves[currentSantaMove] = 1;
    }
}

void ToRun::addRoboMove(int move)
{
    switch (move){
    case 0:
        currentRoboSantaMove += 10000;
        break;
    case 1:
        currentRoboSantaMove += 1;
        break;
    case 2:
        currentRoboSantaMove -= 10000;
        break;
    case 3:
        currentRoboSantaMove -= 1;
        break;
    }
    if (moves[currentRoboSantaMove == NULL]){
        moves[currentRoboSantaMove] = 1;
    }
}

