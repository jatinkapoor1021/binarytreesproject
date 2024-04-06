#include <vector>
#include <algorithm>
#include "myVector.hpp"

void vectorMedian(const std::vector<int>* instructions) {
    std::vector<int> data;
    std::vector<int> medians;
    for (int instruction : *instructions) {
        if (instruction > 0) { // Insert
            auto it = std::lower_bound(data.begin(), data.end(), instruction);
            data.insert(it, instruction);
        } else { // Pop median
            int medianIndex = data.size() / 2;
            medians.push_back(data[medianIndex]);
            data.erase(data.begin() + medianIndex);
        }
    }
    // Print medians
    for (int median : medians) {
        std::cout << median << " ";
    }
    std::cout << std::endl;
}
