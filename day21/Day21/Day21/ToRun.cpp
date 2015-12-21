#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    readInInput();
    findSolution();
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

    weapons.push_back(Item(8, 4, 0, 0));
    weapons.push_back(Item(10, 5, 0, 0));
    weapons.push_back(Item(25, 6, 0, 0));
    weapons.push_back(Item(40, 7, 0, 0));
    weapons.push_back(Item(74, 8, 0, 0));

    armor.push_back(Item(13, 0, 1, 1));
    armor.push_back(Item(31, 0, 2, 1));
    armor.push_back(Item(53, 0, 3, 1));
    armor.push_back(Item(75, 0, 4, 1));
    armor.push_back(Item(102, 0, 5, 1));

    rings.push_back(Item(25, 1, 0,2));
    rings.push_back(Item(50, 2, 0, 2));
    rings.push_back(Item(100, 3, 0, 2));
    rings.push_back(Item(20, 0, 1, 2));
    rings.push_back(Item(40, 0, 2, 2));
    rings.push_back(Item(80, 0, 3, 2));








    boss.hitPoints = 100;
    boss.attack = 8;
    boss.armor = 2;


}

void ToRun::findSolution(){
    int maxCost = 0;
    for (int i = 0; i < weapons.size(); i++){
        for (int j = 0; j < armor.size()+1; j++){
            for (int k = 0; k < rings.size() + 1; k++){
                for (int l = 0; l < rings.size() + 1; l++){
                    Player player;
                    player.hitPoints = 100;
                    int curCost = 0;
                    Item wep = weapons.at(i);
                    player.attack = wep.attack;
                    curCost += wep.cost;
                    if (j != armor.size()){
                        Item arm = armor.at(j);
                        player.armor = arm.defense;
                        curCost += arm.cost;
                    }

                    if (k != rings.size()){
                        player.armor += rings.at(k).defense;
                        player.attack += rings.at(k).attack;
                        curCost += rings.at(k).cost;
                    }
                    if (l != rings.size() && k != l){
                        player.armor += rings.at(l).defense;
                        player.attack += rings.at(l).attack;
                        curCost += rings.at(l).cost;
                    }



                    if (!evalBattle(player, boss)){
                        if (curCost > maxCost){
                            maxCost = curCost;
                        }
                    }
                }
            }
        }
    }
    maxCost += 0;
}


bool ToRun::evalBattle(Player player, Player boss){
    bool toReturn = false;
    while (true){
        if (player.attack <= boss.armor){
            boss.hitPoints -= 1;
        }
        else{
            boss.hitPoints -= (player.attack - boss.armor);
        }

        if (boss.hitPoints <= 0){
            return true;
        }

        if (boss.attack <= player.armor){
            player.hitPoints -= 1;
        }
        else{
            player.hitPoints -= (boss.attack - player.armor);
        }
        if (player.hitPoints <= 0){
            return false;
        }
    }

    return toReturn;
}