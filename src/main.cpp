//
// Created by Nickt on 5/06/2022.
//

#include <iostream>
#include <fstream>
#include "strings.h"


int main(int argc, const char *argv[])
{
    std::ifstream inFile("src/resources/input_test.txt");
    std::ofstream outFile("src/resources/output.txt");
    std::string line;
    std::vector<std::string> fish = {};
    int days = 2;

    if (!inFile || !outFile)
    {
        printf("Files could not be opened");
        return 1;
    }

    while (std::getline(inFile, line))
    {
        stringSplit(line, ',', fish);
    }

    outFile << "Initial state: " << line << std::endl;

    for (int i = 1; i <= days; i++)
    {
        if (i == 1)
        {
            outFile << "After " << i << " day:   ";
        } else {
            outFile << "After " << i << " days:  ";
        }

        for (int j = 0; j < fish.size(); j++)
        {
            outFile << fish[j] << ",";
        }
        outFile << "\n";
    }

    inFile.close();
    outFile.close();


    return 0;
}
