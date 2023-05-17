//
// Created by 田佳业 on 2023/4/19.
//
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = { 1, 2, 3, 2, 4, 5, 2 };
    const auto value_to_remove = 2;
//    vec.erase(std::remove(vec.begin(), vec.end(), value_to_remove), vec.end());
    std::remove(vec.begin(),vec.end(),value_to_remove);
    for (const auto& i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
