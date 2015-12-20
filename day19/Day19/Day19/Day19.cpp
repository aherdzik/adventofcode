// Day19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ToRun.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>
using Reps = std::multimap<std::string, std::string>;

Reps readInput(std::string& molecule)
{
    std::ifstream infile("Text.txt");
    std::string line;
    std::regex rex("(\\w+) => (\\w+)");
    std::smatch match;
    Reps replacements;

    while (std::getline(infile, line))
    {
        if (std::regex_match(line, match, rex))
        {
            if (match.size() < 3)
                return replacements;
            replacements.insert(std::make_pair(match[1], match[2]));
        }
        else {
            molecule = line;
        }
    }
    return replacements;
}

int partOne(Reps& replacements, std::string& molecule)
{
    std::map<std::string, int> newMolecules;
    for (const auto& rep : replacements)
    {
        size_t pos = molecule.find(rep.first, 0);
        while (pos != std::string::npos)
        {
            std::string mol = molecule;
            mol.replace(pos, rep.first.length(), rep.second);
            newMolecules[mol] = 1;
            pos = molecule.find(rep.first, pos + 1);
        }
    }
    return newMolecules.size();
}

int createMolecule(Reps& replacements, std::string& source)
{
    int steps = 0;

    for (;;)
    {
        for (const auto& rep : replacements)
        {
            auto pos = source.find(rep.first, 0);
            if (pos != std::string::npos)
            {
                source.replace(pos, rep.first.length(), rep.second);
                steps++;
            }
            if (source == "e")
                return steps;
        }
    }

    return steps;
}

Reps reverseMap(Reps& source)
{
    Reps rest;
    for (auto& element : source)
    {
        rest.insert(std::make_pair(element.second, element.first));
    }
    return rest;
}

int partTwo(Reps& replacements, std::string& molecule)
{
    return createMolecule(reverseMap(replacements), molecule);
}


int _tmain(int argc, _TCHAR* argv[])
{
    std::string molecule;
    Reps replacements = readInput(molecule);
    std::cout << "Part one: " << partOne(replacements, molecule) << std::endl;
    std::cout << "Part two: " << partTwo(replacements, molecule) << std::endl;
	return 0;
}





