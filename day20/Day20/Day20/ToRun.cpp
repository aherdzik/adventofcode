#include "stdafx.h"
#include "ToRun.h"

ToRun::ToRun()
{
    bool keepRunning = true;
    int currentNum = 1;
    int targetNum = 29000000;
    
    while (keepRunning){
        currentNum++;
        

        if (evalPresents2(currentNum) >= targetNum){
            keepRunning = false;
        }
    }
    currentNum += 0;
}


ToRun::~ToRun()
{
}

int ToRun::evalPresents(int count){
    int numCount = count*10 + 10;
    int z = 2;
    int presentDelivers = 0;
    while (z * z <= count){
        if (count % z == 0){
                numCount += z * 10;
                presentDelivers++;
            if (z*z != count){
                numCount += (count / z)*10;
                presentDelivers++;
            }
        }
        z++;
    }
    return numCount;
    
}

int ToRun::evalPresents2(int count){
    int numCount = count*11 + 11;
    int z = 2;
    int presentDelivers = 0;
    while (z * z <= count){
        if (count % z == 0){
            if (z * 50 >= count){
                numCount += z * 11;
                presentDelivers++;
            }
            if (z*z != count && (count / z) * 50 >= count){
                numCount += (count / z) * 11;
                presentDelivers++;
            }
        }
        z++;
    }
    return numCount;

}
