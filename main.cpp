
#include <iostream>
#include <fstream>
#include <vector>
#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include "myAVLtree.hpp"

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    vector<string> instructions;
    string instruction;
    
    // Read instructions from file
    while (getline(inputFile, instruction)) {
        instructions.push_back(instruction);
    }

    // Using vector method
    vectorMedian(&instructions);

    // Using list method
    listMedian(&instructions);

    // Using heap method
    heapMedian(&instructions);

    // Using AVL tree method
    treeMedian(&instructions);

    return 0;
}
