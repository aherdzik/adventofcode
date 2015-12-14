#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    fillData();
    runSim();
    int result = 0;
    for (Reindeer r : reindeerVector){
        if (result < r.currentPoints){
            result = r.currentPoints;
        }
    }
    result += 0;
}


ToRun::~ToRun()
{
}


void ToRun::fillData(){
    reindeerVector = vector<Reindeer>();
    reindeerVector.push_back(createReindeer("Rudolph", 22,8,8,165,0));
    reindeerVector.push_back(createReindeer("Cupid", 8, 17, 17, 114, 0));
    reindeerVector.push_back(createReindeer("Prancer", 18, 6, 6, 103, 0));
    reindeerVector.push_back(createReindeer("Donner", 25, 6, 6, 145, 0));
    reindeerVector.push_back(createReindeer("Dasher", 11, 12, 12, 125, 0));
    reindeerVector.push_back(createReindeer("Comet", 21, 6, 6, 121, 0));
    reindeerVector.push_back(createReindeer("Blitzen", 18, 3, 3, 50, 0));
    reindeerVector.push_back(createReindeer("Vixen", 20, 4, 4, 75, 0));
    reindeerVector.push_back(createReindeer("Dancer", 7, 20, 20, 119, 0));

}

Reindeer ToRun::createReindeer(string name, int vel, int stam, int stamLeft, int restTime, int restTimeLeft){
    Reindeer toReturn;
    toReturn.name = name;
    toReturn.velocity = vel;
    toReturn.stamina = stam;
    toReturn.staminaLeft = stamLeft;
    toReturn.restTime = restTime;
    toReturn.restTimeLeft = restTimeLeft;
    return toReturn;
}

void ToRun::runSim(){
    for (int i = 0; i < 2503; i++){
        for (int j = 0; j < reindeerVector.size(); j++){
            if (reindeerVector[j].staminaLeft > 0){
                reindeerVector[j].staminaLeft--;
                reindeerVector[j].currentDistance += reindeerVector[j].velocity;
                if (currentLead < reindeerVector[j].currentDistance){
                    currentLead = reindeerVector[j].currentDistance;
                }
                if (reindeerVector[j].staminaLeft == 0){
                    reindeerVector[j].restTimeLeft = reindeerVector[j].restTime;
                }
            }
            else if (reindeerVector[j].restTimeLeft > 0){
                reindeerVector[j].restTimeLeft--;
                if (reindeerVector[j].restTimeLeft == 0){
                    reindeerVector[j].staminaLeft = reindeerVector[j].stamina;
                }
            }
        }

        for (int j = 0; j < reindeerVector.size(); j++){
            if (reindeerVector[j].currentDistance == currentLead){
                reindeerVector[j].currentPoints++;
            }
        }
    }
}