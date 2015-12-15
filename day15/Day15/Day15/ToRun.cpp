#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    maxValue = 0;
    fillData();
    maxValue = findMaxValue();
    maxValue += 0;
}


ToRun::~ToRun()
{
}

void ToRun::fillData(){
    iData[0][0] = 5;
    iData[0][1] = -1;
    iData[0][2] = 0;
    iData[0][3] = 0;
    iData[0][4] = 5;

    iData[1][0] = -1;
    iData[1][1] = 3;
    iData[1][2] = 0;
    iData[1][3] = 0;
    iData[1][4] = 1;

    iData[2][0] = 0;
    iData[2][1] = -1;
    iData[2][2] = 4;
    iData[2][3] = 0;
    iData[2][4] = 6;

    iData[3][0] = -1;
    iData[3][1] = 0;
    iData[3][2] = 0;
    iData[3][3] = 2;
    iData[3][4] = 8;
}

int ToRun::findMaxValue(){
    for (int i = 0; i <= 100; i++){
        for (int j = 0; j<=100; j++){
            for (int k = 0; k <=100; k++){
                for (int l= 0; l <=100; l++){
                    if (i + j + k + l == 100){
                        int capacity = (i * iData[0][0]) + (j * iData[1][0]) + (k * iData[2][0]) + (l * iData[3][0]);
                        int durability = (i * iData[0][1]) + (j * iData[1][1]) + (k * iData[2][1]) + (l * iData[3][1]);
                        int flavor = (i * iData[0][2]) + (j * iData[1][2]) + (k * iData[2][2]) + (l * iData[3][2]);
                        int texture = (i * iData[0][3]) + (j * iData[1][3]) + (k * iData[2][3]) + (l * iData[3][3]);
                        int calories = (i * iData[0][4]) + (j * iData[1][4]) + (k * iData[2][4]) + (l * iData[3][4]);

                        if (capacity < 0){
                            capacity = 0;
                        }
                        if (durability < 0){
                            durability = 0;
                        }
                        if (flavor < 0){
                            flavor = 0;
                        }
                        if (texture < 0){
                            texture = 0;
                        }

                        if (calories == 500){

                            int score = capacity* durability * flavor * texture;
                            if (score > maxValue)
                                maxValue = score;
                        }
                            
                    }

                }
            }
        }
    }
    return maxValue;
}
