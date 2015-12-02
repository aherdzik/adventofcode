#include "stdafx.h"
#include "ToRun.h"

ToRun::ToRun()
{
    dataHolder = vector<DataHolder>();
    run();
   
}


ToRun::~ToRun()
{
}

void ToRun::run(){
    fillDataHolder();
    int result = ribbonNeededForAllBoxes();

}

void ToRun::fillDataHolder(){
    ifstream myfile;
    string line;
    myfile.open("Text.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            vector<string> splitString = split(line, 'x');
            DataHolder d;
            for (int i = 0; i < splitString.size(); i++){
                int curNum = stoi(splitString[i]);
                switch (i){
                case 0:
                    d.l = curNum;
                    break;
                case 1:
                    d.w = curNum;
                    break;
                case 2:
                    d.h = curNum;
                    break;
                }

            }
            dataHolder.push_back(d);

        }
        myfile.close();
    }
}

int ToRun::paperNeededForAllBoxes()
{
    int runningTotal = 0;
    for (DataHolder d : dataHolder){
        runningTotal += paperNeededForBox(d);
    }
    return runningTotal;
}

int ToRun::paperNeededForBox(DataHolder d){
    int curTotal = (2 * d.l*d.w) + (2 * d.w*d.h) + (2 * d.h*d.l);
    vector<int> sortingVector = vector<int>();
    sortingVector.push_back(d.l);
    sortingVector.push_back(d.w);
    sortingVector.push_back(d.h);
    sort(sortingVector.begin(), sortingVector.end());
    curTotal += (sortingVector[0] * sortingVector[1]);
    return curTotal;

}


int ToRun::ribbonNeededForAllBoxes()
{
    int runningTotal = 0;
    for (DataHolder d : dataHolder){
        runningTotal += ribbonNeededForBox(d);
    }
    return runningTotal;
}

int ToRun::ribbonNeededForBox(DataHolder d){
    int curTotal = d.h * d.l * d.w;
    vector<int> sortingVector = vector<int>();
    sortingVector.push_back(d.l);
    sortingVector.push_back(d.w);
    sortingVector.push_back(d.h);
    sort(sortingVector.begin(), sortingVector.end());
    curTotal += sortingVector[0] + sortingVector[0] + sortingVector[1] + sortingVector[1];

    return curTotal;
}





std::vector<std::string> & ToRun::split(const std::string &s, char delim, std::vector<std::string> &elems) {
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