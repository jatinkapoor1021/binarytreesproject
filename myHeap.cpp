#include "myHeap.hpp"

void heapMedian(const std::vector<int> *instructions)
{
    std::priority_queue<int, std::vector<int>, std::less<int>> small;

    std::priority_queue<int, std::vector<int>, std::greater<int>> large;

    std::vector<int> medians;

    auto start = std::chrono::high_resolution_clock::now();

    for (auto it = instructions->begin(); it != instructions->end(); ++it)
    {
        if (*it != -1)
        {
            if (small.empty() || *it <= small.top())
            {
                small.push(*it);
            }
            else
            {
                large.push(*it);
            }

            while (small.size() > large.size() + 1)
            {
                large.push(small.top());
                small.pop();
            }
            while (large.size() > small.size())
            {
                small.push(large.top());
                large.pop();
            }
        }
        else
        {
            if (!small.empty())
            {
                medians.push_back(small.top());
                small.pop();

                while (small.size() < large.size())
                {
                    small.push(large.top());
                    large.pop();
                }
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