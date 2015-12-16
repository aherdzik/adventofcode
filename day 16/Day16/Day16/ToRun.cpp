#include "stdafx.h"
#include "ToRun.h"


ToRun::ToRun()
{
    readInData();
    int result = findAunt();
    result += 0;
}


ToRun::~ToRun()
{
}

void ToRun::readInData(){
    string line;
    ifstream myfile("Text.txt");
    if (myfile.is_open())
    {
        int counter = 0;
        while (getline(myfile, line))
        {
            int input[10];
            for (int i = 0; i < 10; i++){
                input[i] = -1;
            }
            vector<string> splitString = split(line, ' ');
            for (int i = 2; i < splitString.size(); i+=2){
                string subject = splitString.at(i);
                int subjectIndex = -1;
                if (subject == "children:"){
                    subjectIndex = 0;
                }
                else if(subject == "cats:"){
                    subjectIndex = 1;
                }
                else if (subject == "samoyeds:"){
                    subjectIndex = 2;
                }
                else if (subject == "pomeranians:"){
                    subjectIndex = 3;
                }
                else if (subject == "akitas:"){
                    subjectIndex = 4;
                }
                else if (subject == "vizslas:"){
                    subjectIndex = 5;
                }
                else if (subject == "goldfish:"){
                    subjectIndex = 6;
                }
                else if (subject == "trees:"){
                    subjectIndex = 7;
                }
                else if (subject == "cars:"){
                    subjectIndex = 8;
                }
                else if (subject == "perfumes:"){
                    subjectIndex = 9;
                }

                if (counter == 61){
                    counter += 0;
                }

                string objString="";
                if (i == splitString.size() - 2){
                    objString = string(splitString.at(i + 1).begin(), splitString.at(i + 1).end());
                }
                else{
                    objString = string(splitString.at(i + 1).begin(), splitString.at(i + 1).end() - 1);
                }
               
                int objNum = atoi(objString.c_str());
                input[subjectIndex] = objNum;
            }

            for (int i = 0; i < 10; i++){
                dataHolder[counter][i] = input[i];
            }


            counter++;
        }
        myfile.close();
    }
}


int ToRun::findAunt(){
    int correctAunt[10] = {3,7,2,3,0,0,5,3,2,1};
    for (int i = 0; i < 500; i++){
        bool foundMatch = true;
        if (i == 61){
            i += 0;
        }
        for (int j = 0; j < 10; j++){
            if (dataHolder[i][j] == -1)
                continue;
            else{
                if (j == 1 || j == 7){
                    if (dataHolder[i][j] <= correctAunt[j]){
                        foundMatch = false;
                        break;
                    }
                }
                else if (j == 3 || j == 6){
                    int auntVal = dataHolder[i][j];
                    int checkVal = correctAunt[j];
                    if (auntVal >= checkVal){
                        foundMatch = false;
                        break;
                    }
                }
                else{
                    if (dataHolder[i][j] != correctAunt[j]){
                        foundMatch = false;
                        break;
                    }
                }
                
            }
        }

        if (foundMatch){
            return i + 1;
        }
    }

    return -1;
}

std::vector<std::string>  ToRun:: split(const std::string &s, char delim, std::vector<std::string> &elems) {
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