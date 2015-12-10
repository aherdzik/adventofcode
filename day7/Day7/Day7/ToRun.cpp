#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    commands = vector<WireCommand>();
    for (int i = 0; i < 676; i++){
        wireValues[i] = -1;
    }
    getInput();
    runProgram();
}


ToRun::~ToRun()
{
}

void ToRun::getInput(){
    string line;
    ifstream myfile("Text.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            commands.push_back(parseLine(line));
        }
        myfile.close();
    }
}

WireCommand ToRun::parseLine(string line){
    WireCommand toReturn;
    vector<string> splitString;
    split(splitString, line, " ");
    if (splitString[0] == "NOT"){
        toReturn.commandType = CommandType::NOT;
        toReturn.input2 = stringToInt(splitString[1]);
        toReturn.input2IsLocation = ((splitString[1].at(0) - 'a') >= 0);
        toReturn.destination = stringToInt(splitString[3]);
    }
    else if(splitString.size()==3){
        toReturn.commandType = CommandType::NONE;
        toReturn.input1 = stringToInt(splitString[0]);
        toReturn.input1IsLocation= ((splitString[0].at(0) - 'a') >= 0);
        toReturn.destination = stringToInt(splitString[2]);
    }
    else{
        toReturn.input1 = stringToInt(splitString[0]);
        toReturn.input1IsLocation = ((splitString[0].at(0) - 'a') >= 0);
        if (splitString[1] == "AND"){
            toReturn.commandType = CommandType::AND;
        }
        else if (splitString[1] == "OR"){
            toReturn.commandType = CommandType::OR;
        }
        else if (splitString[1] == "LSHIFT"){
            toReturn.commandType = CommandType::LSHIFT;
        }
        else if (splitString[1] == "RSHIFT"){
            toReturn.commandType = CommandType::RSHIFT;
        }
        toReturn.input2 = stringToInt(splitString[2]);
        toReturn.input2IsLocation = ((splitString[2].at(0) - 'a') >= 0);
        toReturn.destination = stringToInt(splitString[4]);

    }
    return toReturn;
}

void ToRun::runProgram(){
    while (wireValues[0] == -1){
        for (WireCommand curCommand : commands){
            runCommand(curCommand);
        }
    }
    int heldValue = wireValues[0];

    for (int i = 0; i < 676; i++){
        wireValues[i] = -1;
    }
    wireValues[1] = heldValue;
    for (int i = 0; i < commands.size(); i++){
        if (commands[i].destination == 1){
            commands.erase(commands.begin() + i);
        }
    }

    while (wireValues[0] == -1){
        for (WireCommand curCommand : commands){
            runCommand(curCommand);
        }
    }
    int newValue = wireValues[0];


}

void ToRun::runCommand(WireCommand curCommand)
{
    if (curCommand.destination == 1){
        curCommand.destination += 0;
    }
    switch (curCommand.commandType){
    case CommandType::NONE:
        if (curCommand.input1IsLocation){
            int input1 = wireValues[curCommand.input1] != -1 ? wireValues[curCommand.input1] : -1;
            if (input1 != -1){
                wireValues[curCommand.destination] = input1;
            }
            
        }
        else{
            wireValues[curCommand.destination] = curCommand.input1;
        }
        break;
    case CommandType::AND:
    case CommandType::OR:
    case CommandType::LSHIFT:
    case CommandType::RSHIFT:
    case CommandType::NOT:
        int input1 = -1;
        if (curCommand.input1IsLocation){
            input1 = wireValues[curCommand.input1] != -1 ? wireValues[curCommand.input1] : -1;
        }
        else{
            input1 = curCommand.input1 != -1 ? curCommand.input1 : -1;
        }

        int input2 = -1;
        if (curCommand.input2IsLocation){
            input2 = wireValues[curCommand.input2] != -1 ? wireValues[curCommand.input2] : -1;
        }
        else{
            input2 = curCommand.input2 != -1 ? curCommand.input2 : -1;
        }

        if (curCommand.commandType == CommandType::NOT){
            if (input2 != -1){
                wireValues[curCommand.destination] = resolveWire(-1, input2, CommandType::NOT);
            }
        }
        else{
            if (input1!=-1 && input2 != -1){
                wireValues[curCommand.destination] = resolveWire(input1, input2, curCommand.commandType);
            }
        }
    
        break;

    }
}




template <typename Container>
Container& ToRun::split(
  Container&                            result,
  const typename Container::value_type& s,
  const typename Container::value_type& delimiters,
  split::empties_t                      empties )
{
  result.clear();
  size_t current;
  size_t next = -1;
  do
  {
    if (empties == split::no_empties)
    {
      next = s.find_first_not_of( delimiters, next + 1 );
      if (next == Container::value_type::npos) break;
      next -= 1;
    }
    current = next + 1;
    next = s.find_first_of( delimiters, current );
    result.push_back( s.substr( current, next - current ) );
  }
  while (next != Container::value_type::npos);
  return result;
}

int ToRun::resolveWire(int input1, int input2, CommandType commandType){
    int toReturn = -1;
    switch (commandType){
    case CommandType::AND:
        toReturn = input1 & input2;
        break;
    case CommandType::OR:
        toReturn = input1 | input2;
        break;
    case CommandType::LSHIFT:
        toReturn = input1 << input2;
        break;
    case CommandType::RSHIFT:
        toReturn = input1 >> input2;
        break;
    case CommandType::NOT:
        toReturn = 65535 - input2;
        break;
    }

    return toReturn;
}

int ToRun::stringToInt(string s){

    if (s.at(0) - 'a' < 0){
        return stoi(s);
    }


    int toReturn = 0;
    if (s.size() == 1){
        char letter1 = s.at(0);
        toReturn= letter1 - 'a';
    }
    else{
        char letter1 = s.at(0);
        char letter2 = s.at(1);
        toReturn = letter2 - 'a';
        toReturn += 26 * ((letter1 - 'a') )+ 26;
    }
    return toReturn;
}