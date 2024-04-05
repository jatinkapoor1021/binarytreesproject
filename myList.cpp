#include "myList.hpp"
#include <list>
#include <algorithm>

void listMedian(const std::vector<std::string>* instructions) {
    std::list<int> lst;
    for (const std::string& instruction : *instructions) {
        if (instruction == "pop median") {
            lst.sort();
            auto it = lst.begin();
            std::advance(it, lst.size() / 2);
            int median = *it;
            std::cout << median << " ";
            lst.erase(it);
        } else {
            int value = std::stoi(instruction.substr(7)); // Extract value from instruction
            lst.push_back(value);
        }
    }
}
