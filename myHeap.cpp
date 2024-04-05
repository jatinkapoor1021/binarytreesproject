#include "myHeap.hpp"
#include <queue>

void heapMedian(const std::vector<std::string>* instructions) {
    std::priority_queue<int> small; // Max heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> large; // Min heap
    for (const std::string& instruction : *instructions) {
        if (instruction == "pop median") {
            int median = small.top();
            std::cout << median << " ";
            small.pop();
            // Rebalance if necessary
            if (small.size() < large.size()) {
                small.push(large.top());
                large.pop();
            }
        } else {
            int value = std::stoi(instruction.substr(7)); // Extract value from instruction
            if (small.empty() || value <= small.top()) {
                small.push(value);
            } else {
                large.push(value);
            }
            // Rebalance if necessary
            if (small.size() > large.size() + 1) {
                large.push(small.top());
                small.pop();
            } else if (small.size() < large.size()) {
                small.push(large.top());
                large.pop();
            }
        }
    }
}
