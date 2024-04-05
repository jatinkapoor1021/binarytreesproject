#include "myAVLtree.hpp"
#include <map>

void treeMedian(const std::vector<std::string>* instructions) {
    std::map<int, int> smallTree; // AVL tree for elements less than or equal to the median
    std::map<int, int> largeTree; // AVL tree for elements greater than the median
    for (const std::string& instruction : *instructions) {
        if (instruction == "pop median") {
            auto it = smallTree.end();
            --it;
            int median = it->first;
            std::cout << median << " ";
            if (it->second == 1) {
                smallTree.erase(it);
            } else {
                it->second--;
            }
            // Rebalance if necessary
            if (smallTree.size() < largeTree.size()) {
                auto it2 = largeTree.begin();
                smallTree.insert(*it2);
                largeTree.erase(it2);
            }
        } else {
            int value = std::stoi(instruction.substr(7)); // Extract value from instruction
            if (smallTree.empty() || value <= smallTree.rbegin()->first) {
                smallTree[value]++;
            } else {
                largeTree[value]++;
            }
            // Rebalance if necessary
            if (smallTree.size() > largeTree.size() + 1) {
                auto it = smallTree.end();
                --it;
                largeTree.insert(*it);
                smallTree.erase(it);
            } else if (smallTree.size() < largeTree.size()) {
                auto it = largeTree.begin();
                smallTree.insert(*it);
                largeTree.erase(it);
            }
        }
    }
}
