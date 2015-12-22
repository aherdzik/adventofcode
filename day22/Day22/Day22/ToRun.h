#pragma once
// reading a text file
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
class ToRun
{
    struct Spell{
        string spellName;
        int turnsLeft;
        int manaCost;
        int type;
        Spell(string sp, int t, int m, int ty) :spellName(sp), turnsLeft(t), manaCost(m), type(ty){

        }
    };


public:
    ToRun();
    ~ToRun();
    void readInInput();
    void runProgram();

    std::vector<std::string> split(const std::string &s, char delim);
    std::vector<std::string> split(const std::string &s, char delim, std::vector<std::string> &elems);
    bool evalBattle(vector<int>commands);
    int bossHP = 55;
    int bossAttack = 8;
    int currentMana = 500;
    int playerHP = 50;
    int rechargeTurn = 0;
    int shieldTurn = 0;
    int poisonTurn = 0;
    int victoryIndicator = 0;
    int manaUsed = 0;
    int moveIter = 0;

    void castSpell(int spell);
    int checkForDeath();
    int beginningOfTurn();
    int evalMoves(vector<int>moves);

};

