#include <list>
#include "myList.hpp"

void listMedian(const std::vector<int>* instructions) {
    std::list<int> data;
    std::vector<int> medians;
    for (int instruction : *instructions) {
        if (instruction > 0) { // Insert
            auto it = data.begin();
            while (it != data.end() && *it < instruction) ++it;
            data.insert(it, instruction);
        } else { // Pop median
            int medianIndex = data.size() / 2;
            auto it = data.begin();
            std::advance(it, medianIndex);
            medians.push_back(*it);
            data.erase(it);
        }
    }
    // Print medians
    for (int median : medians) {
        std::cout << median << " ";
    }
    std::cout << std::endl;
}
