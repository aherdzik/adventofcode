#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    //readInInput();
    runProgram();
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

            iter++;
        }
        myfile.close();
    }
}

std::vector<std::string> ToRun::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> ToRun::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

void ToRun::runProgram(){

    bool boolIter[28];
    for (int i = 0; i < 28; i++){
        boolIter[i] = false;
    }


    bool isFinished = false;



    srand(time(NULL));
    
    //1309
    //1295 34234200000

    int maxManaSpent = 9999;
    
    vector<int> winningMoves;
    while (maxManaSpent >=1289){
        vector<int> moves = vector<int>();
        for (int i = 0; i < 25; i++){
            moves.push_back((int)(rand() % 5));
        }
        int result = evalMoves(moves);
        if (result != -1 && result < maxManaSpent){
            maxManaSpent = result;
            winningMoves = moves;
        }

    }
    maxManaSpent += 0;

}

void ToRun::castSpell(int spell){
    switch (spell){
    case 0:
        bossHP -= 4;
        currentMana -= 53;
        manaUsed += 53;
        break;
    case 1:
        bossHP -= 2;
        playerHP += 2;
        currentMana -= 73;
        manaUsed += 73;
        break;
    case 2:
        shieldTurn = 6;
        currentMana -= 113;
        manaUsed += 113;
        break;
    case 3:
        poisonTurn = 6;
        currentMana -= 173;
        manaUsed += 173;
        break;
    case 4:
        rechargeTurn = 5;
        currentMana -= 229;
        manaUsed += 229;
        break;
    
    }

    if (currentMana < 0){
        //cout << "not enough mana";
        playerHP = -50;
    }

    moveIter++;

}

int ToRun::checkForDeath(){
    if (playerHP <= 0){
        return 2;
    }
    if (bossHP <= 0){
        return 1;
    }
    
    return 0;
}

int ToRun::beginningOfTurn(){
    if (poisonTurn > 0){
        bossHP -= 3;
        poisonTurn--;
        if (bossHP <= 0){
            victoryIndicator = 1;
        }
    }
    if (shieldTurn > 0){
        shieldTurn--;
    }
    if (rechargeTurn > 0){
        currentMana += 101;
        rechargeTurn--;
    }

    //cout << "Beginning of turn: \n";
    //cout << "Player HP: " + playerHP << " boss HP: " << bossHP << "current Mana: " << currentMana << "\n";
    return checkForDeath();
}

int ToRun::evalMoves(vector<int> moves){

    bossHP = 55;
    bossAttack = 8;
    currentMana = 500;
    playerHP = 50;
    rechargeTurn = 0;
    shieldTurn = 0;
    poisonTurn = 0;
    victoryIndicator = 0;
    manaUsed = 0;
    moveIter = 0;



    while (victoryIndicator == 0){
        playerHP -= 1;
        victoryIndicator = checkForDeath();
        if (victoryIndicator > 0)
            break;
        //begin players turn
        victoryIndicator = beginningOfTurn();
        if (victoryIndicator > 0)
            break;

        //playerMove
        castSpell(moves.at(moveIter));
        victoryIndicator = checkForDeath();
        if (victoryIndicator > 0)
            break;

        //begin boss turn
        victoryIndicator = beginningOfTurn();
        if (victoryIndicator > 0)
            break;


        //bossMove
        if (shieldTurn > 0){
            playerHP -= 1;
        }
        else{
            playerHP -= 8;
        }
        victoryIndicator = checkForDeath();
        if (victoryIndicator > 0)
            break;


    }

    if (victoryIndicator == 1){
        return manaUsed;
    }
    else{
        return -1;
    }
}




