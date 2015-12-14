#pragma once
#include <string>
#include <vector>
using namespace std;

struct Reindeer {
    string name = "defaultName";
    int velocity = 0;
    int stamina = 0;
    int staminaLeft = 0;
    int restTime = 0;
    int restTimeLeft = 0;
    int currentDistance = 0;
    int currentPoints = 0;
};
class ToRun
{
public:
    void fillData();
    int currentLead = 0;
    void runSim();
    vector<Reindeer> reindeerVector;
    Reindeer createReindeer(string name, int vel, int stam, int stamLeft, int restTime, int restTimeLeft);
    ToRun();
    ~ToRun();
};

