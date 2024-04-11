#include "myAVLtree.hpp"


//treeMedian function defined
void treeMedian(const std::vector<int> *instructions)
{

//sizes
    AVL_Tree small;

    AVL_Tree large;

    std::vector<int> medians;
//auto start function
    auto start = std::chrono::high_resolution_clock::now();

    int small_size = 0, large_size = 0;
//loop
    for (auto it = instructions->begin(); it != instructions->end(); ++it)
    {
        if (*it != -1)
        {
            if (small.isEmpty() || *it <= small.getMaximum())
            {
                small.insert(*it);
                small_size++;
            }
            else
            {
                large.insert(*it);
                large_size++;
            }

            while (small_size > large_size + 1)
            {
                large.insert(small.getMaximum());
                large_size++;

                small.remove(small.getMaximum());
                small_size--;
            }

            while (large_size > small_size)
            {
                small.insert(large.getMinimum());
                small_size++;

                large.remove(large.getMinimum());
                large_size--;
            }
        }
        else
        {
            medians.push_back(small.getMaximum());
            small.remove(small.getMaximum());
            small_size--;

            while (small_size < large_size)
            {
                small.insert(large.getMinimum());
                small_size++;

                large.remove(large.getMinimum());
                large_size--;
            }
        }
    }
//auto end function
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    for (int median : medians)
    {
        std::cout << median << " ";
    }
    std::cout << "\n";

    
}
