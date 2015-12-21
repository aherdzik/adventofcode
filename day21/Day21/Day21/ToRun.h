#pragma once
// reading a text file
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Player{
    int hitPoints= 100;
    int attack = 0;
    int armor= 0;
};

struct Item{
    int cost;
    int defense;
    int attack;
    int type;

    Item(int c, int a, int d, int t) :cost(c), defense(d), attack(a), type(t){

    }
};
class ToRun
{
public:
    ToRun();
    ~ToRun();
    Player boss;
    Player player;
    vector<Item> items;
    vector<Item> weapons;
    vector<Item> armor;
    vector<Item> rings;
    void readInInput();
    void findSolution();
    bool evalBattle(Player player, Player boss);
};

