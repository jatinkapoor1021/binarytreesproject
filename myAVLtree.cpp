#include "myAVLtree.hpp"

void treeMedian(const std::vector<int>* instructions) {
    AVLTree small;
    AVLTree large;
    std::vector<int> medians;
    for (int instruction : *instructions) {
        if (instruction > 0) { // Insert
            if (small.isEmpty() || instruction <= small.getMedian()) {
                small.insert(instruction);
            } else {
                large.insert(instruction);
            }
            rebalance(small, large);
        } else { // Pop median
            medians.push_back(small.getMedian());
            small.removeMedian();
            rebalance(small, large);
        }
    }
    // Print medians
    for (int median : medians) {
        std::cout << median << " ";
    }
    std::cout << std::endl;
}
