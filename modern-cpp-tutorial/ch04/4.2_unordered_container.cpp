#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

int main()
{
    std::unordered_map<int, std::string> u = {
        {1, "1"}, {2, "2"}, {3, "3"}};

    std::map<int, std::string> v = {
        {1, "1"}, {2, "2"}, {3, "3"}};

    std::cout << "std::unordered_map" << std::endl;
    for (const auto &n : u)
    {
        std::cout << "Key[" << n.first << "]=[" << n.second << "]" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "std::map" << std::endl;
    for (const auto &n : v)
    {
        std::cout << "Key[" << n.first << "]=[" << n.second << "]" << std::endl;
    }
}