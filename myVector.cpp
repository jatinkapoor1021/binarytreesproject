#include "myVector.hpp"
#include <algorithm>

void vectorMedian(const std::vector<std::string>* instructions) {
    std::vector<int> vec;
    for (const std::string& instruction : *instructions) {
        if (instruction == "pop median") {
            std::sort(vec.begin(), vec.end());
            int median = vec[vec.size() / 2];
            std::cout << median << " ";
            vec.erase(std::remove(vec.begin(), vec.end(), median), vec.end());
        } else {
            int value = std::stoi(instruction.substr(7)); // Extract value from instruction
            vec.push_back(value);
        }
    }
}
