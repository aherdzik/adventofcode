#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    commands = vector<WireCommand>();
    for (int i = 0; i < 676; i++){
        wireValues[i] = -1;
    }
    getInput();
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
        toReturn.destination = stringToInt(splitString[3]);
    }
    else if(splitString.size()==3){
        toReturn.commandType = CommandType::NONE;
        toReturn.input1 = stringToInt(splitString[0]);
        toReturn.destination = stringToInt(splitString[2]);
    }
    else{
        toReturn.input1 = stringToInt(splitString[0]);
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
        toReturn.destination = stringToInt(splitString[4]);

    }
    return toReturn;
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