//clang++ 2.2_if_switch.cpp -std=c++17 -o 2.2_if_switch
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 1,2,3,4 };

    //before c++ 17
    const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);
    if (itr != vec.end()) {
        *itr = 3;
    }

    const std::vector<int>::iterator itr2 = std::find(vec.begin(), vec.end(), 3);
    if (itr2 != vec.end()) {
        *itr2 = 9;
    }

    for (std::vector<int>::iterator el = vec.begin(); el!=vec.end(); ++el) {
        std::cout << *el << std::endl;
    }

    std::cout << "*******" << std::endl;
    //C++ 17 allow variable in if
    if (const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 9);
        itr != vec.end()) {
            *itr = 10;
        }
    for (std::vector<int>::iterator el = vec.begin(); el!=vec.end(); ++el) {
        std::cout << *el << std::endl;
    }

}