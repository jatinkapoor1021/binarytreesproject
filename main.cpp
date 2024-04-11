#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include "myAVLtree.hpp"

std::vector<int> instructionsFromTxt(const std::string &filename)
{
    std::vector<int> instructions;

    std::ifstream fin(filename);

    std::string line, junk, num;

    while (std::getline(fin, line))
    {
        std::istringstream iss(line);

        std::getline(iss, junk, ' ');
        std::getline(iss, num, ' ');

        if (junk != "pop")
        {
            instructions.push_back(std::stoi(num));
        }
        else
        {
            instructions.push_back(-1);
        }
    }

    return instructions;
}

int main()
{

    std::vector<int> v1 = instructionsFromTxt("input1.txt");
    std::vector<int> v2 = instructionsFromTxt("input2.txt");
    std::vector<int> v3 = instructionsFromTxt("input3.txt");

    std::cout << "\n";

    std::cout << "-----------------------------------\n";
    vectorMedian(&v1);

    std::cout << "\n";

    vectorMedian(&v2);

    std::cout << "\n";

    vectorMedian(&v3);

    std::cout << "-----------------------------------\n";

    listMedian(&v1);

    std::cout << "\n";

    listMedian(&v2);

    std::cout << "\n";

    listMedian(&v3);

    std::cout << "-----------------------------------\n";

    heapMedian(&v1);

    std::cout << "\n";

    heapMedian(&v2);

    std::cout << "\n";

    heapMedian(&v3);

    std::cout << "-----------------------------------\n";

    treeMedian(&v1);

    std::cout << "\n";

    treeMedian(&v2);

    std::cout << "\n";

    treeMedian(&v3);

    std::cout << "-----------------------------------\n\n";
    return 0;
}

