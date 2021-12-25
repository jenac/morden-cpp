#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1,2,3,4};
    if (auto iter = std::find(vec.begin(), vec.end(), 3); iter != vec.end()) {
        *iter = 4;
    }

    //read only
    for (auto element: vec) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;

    //write
    for (auto& element: vec) {
        element+=1;
    }

    for (auto element: vec) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;

}