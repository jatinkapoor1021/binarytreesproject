#include "myList.hpp"

void listMedian(const std::vector<int> *instructions)
{
    std::list<int> listMedian;

    std::vector<int> medians;

    auto start = std::chrono::high_resolution_clock::now();

    for (auto it = instructions->begin(); it != instructions->end(); ++it)
    {
        if (*it != -1)
        {
            auto insertAtIndex = listMedian.begin();
            while (insertAtIndex != listMedian.end() && *insertAtIndex < *it)
            {
                ++insertAtIndex;
            }

            if (insertAtIndex == listMedian.end())
            {
                listMedian.push_back(*it);
            }
            else
            {
                listMedian.insert(insertAtIndex, *it);
            }
        }
        else
        {
            if (!listMedian.empty())
            {
                auto medianIndex = listMedian.begin();

                std::advance(medianIndex, (listMedian.size() - 1) / 2);

                medians.push_back(*medianIndex);
                listMedian.erase(medianIndex);
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
