#include "myVector.hpp"

void vectorMedian(const std::vector<int> *instructions)
{
    std::vector<int> vecMedian;

    std::vector<int> medians;

    auto start = std::chrono::high_resolution_clock::now();

    for (auto it = instructions->begin(); it != instructions->end(); ++it)
    {
        if (*it != -1)
        {
            auto insertAtIndex = std::lower_bound(vecMedian.begin(), vecMedian.end(), *it);
            // std::cout << "Inserting " << *it << " at index " << insertAtIndex - vecMedian.begin() << "\n";
            vecMedian.insert(insertAtIndex, *it);
        }
        else
        {
            if (!vecMedian.empty())
            {
                int medianIndex = vecMedian.size() % 2 == 0 ? (vecMedian.size() / 2) - 1 : vecMedian.size() / 2;
                medians.push_back(vecMedian[medianIndex]);
                vecMedian.erase(vecMedian.begin() + medianIndex);
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    for (int median : medians)
    {
        std::cout << median << " ";
    }
    std::cout << "\n";

    // std::cout << "Algorithm duration: " << duration.count() << "ms\n";
}
