#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

enum CommandType{ NOT, OR, RSHIFT, LSHIFT, AND, NONE };

struct split
{
    enum empties_t { empties_ok, no_empties };
};

struct WireCommand{
    int input1 =-1;
    bool input1IsLocation = true;
    int input2 = -1;
    bool input2IsLocation = true;
    CommandType commandType = CommandType::NONE;
    int destination =-1;
};
using namespace std;
class ToRun
{
public:

    
    ToRun();

    void getInput();
    int wireValues[676];
    vector<WireCommand> commands;
    WireCommand parseLine(string line);
    void runProgram();
    int resolveWire(int input1, int input2, CommandType commandType);
    void runCommand(WireCommand curCurCommand);

    template <typename Container>
    Container& split(Container&                            result,
        const typename Container::value_type& s,
        const typename Container::value_type& delimiters,
        split::empties_t                      empties = split::empties_ok);

    int stringToInt(string s);
    ~ToRun();
};

