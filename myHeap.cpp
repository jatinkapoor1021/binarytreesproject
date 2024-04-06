#include <queue>
#include "myHeap.hpp"

void heapMedian(const std::vector<int>* instructions) {
    std::priority_queue<int> small;
    std::priority_queue<int, std::vector<int>, std::greater<int>> large;
    std::vector<int> medians;
    for (int instruction : *instructions) {
        if (instruction > 0) { // Insert
            if (small.empty() || instruction <= small.top()) {
                small.push(instruction);
            } else {
                large.push(instruction);
            }
            rebalance(small, large);
        } else { // Pop median
            medians.push_back(small.top());
            small.pop();
            rebalance(small, large);
        }
    }
    // Print medians
    for (int median : medians) {
        std::cout << median << " ";
    }
    std::cout << std::endl;
}

void rebalance(std::priority_queue<int>& small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large) {
    if (small.size() > large.size() + 1) {
        large.push(small.top());
        small.pop();
    } else if (small.size() < large.size()) {
        small.push(large.top());
        large.pop();
    }
}
