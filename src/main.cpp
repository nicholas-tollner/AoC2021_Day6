//
// Created by Nickt on 5/06/2022.
//

#include <iostream>
#include <fstream>
#include "strings.h"

void decrement(std::vector<std::string> &list);


int main(int argc, const char *argv[])
{
    std::ifstream inFile("src/resources/input.txt");
    std::ofstream outFile("src/resources/output.txt");
    std::string line;
    std::vector<std::string> fish = {};
    int days = 80;

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
        decrement(fish);
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

    std::cout << "Total Fish: " << fish.size() << ", after " << days << " days";

    inFile.close();
    outFile.close();


    return 0;
}

void decrement(std::vector<std::string> &list)
{
    int currentSize = list.size();

    for (int i = 0; i < currentSize; i++)
    {
        if (list[i] == std::to_string(0))
        {
            list[i] = std::to_string(7);
            list.push_back("8");
        }

        list[i] = std::to_string(std::stoi(list[i]) - 1);
    }
}
