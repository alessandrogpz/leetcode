#include <iostream>
#include <vector>

std::vector<int> runningSumOf1DArray(std::vector<int> my_vector)
{
    std::vector<int> new_vector{};
    int c_sum{0};

    for (int i{0}; i < my_vector.size(); i++)
    {
        c_sum += my_vector[i];
        new_vector.push_back(c_sum);
    }

    // Prints new_vector
    // for (int i : new_vector)
    //     std::cout << i << ' ';

    return new_vector;
}