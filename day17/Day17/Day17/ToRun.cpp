#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    readInData();
    runProgram();

}

void ToRun::readInData(){
    dataInput[0] = 43;
    dataInput[1] = 3;
    dataInput[2] = 4;
    dataInput[3] = 10;
    dataInput[4] = 21;
    dataInput[5] = 44;
    dataInput[6] = 4;
    dataInput[7] = 6;
    dataInput[8] = 47;
    dataInput[9] = 41;
    dataInput[10] = 34;
    dataInput[11] = 17;
    dataInput[12] = 17;
    dataInput[13] = 44;
    dataInput[14] = 36;
    dataInput[15] = 31;
    dataInput[16] = 46;
    dataInput[17] = 9;
    dataInput[18] = 27;
    dataInput[19] = 38;
}


ToRun::~ToRun()
{
}

void ToRun::runProgram(){
    int counter = 0;
    int minNum = 0;
    for (int i = 1; i < 1048576; i++){
        int curNum = i;
        if (i == 6000000){
            i += 0;
        }
        bool boolArray[20];
        for (int j = 0; j < 20; j++){
            boolArray[j] = false;
        }
        int iter = 0;
        while (curNum) {
            boolArray[iter] = curNum & 1;
            curNum >>= 1;
            iter++;
        }
        int boolCount = 0;
        for (int k = 0; k < 20; k++){
            if (boolArray[k])
                boolCount++;
        }
        

        
        if (evalCombination(boolArray) == 150){
            counter++;
            if (boolCount ==4)
                minNum ++;
        }
    }
    counter += 0;
}
int ToRun::evalCombination(bool input[20]){
    int result = 0;
    for (int i = 0; i < 20; i++){
        if (input[i]){
            result += dataInput[i];
        }
    }
    return result;
}