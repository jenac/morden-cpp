// clang++ 2.3_auto.cpp -std=c++20 -o 2.3_auto
#include <iostream>

// after C++11
template<typename T, typename U>
auto add2(T x, U y) -> decltype(x+y) {
    return x + y;
}

// after C++14
template<typename T, typename U>
auto add3(T x, U y) {
    return x + y;
}
int main() {
    auto x = 1;
    auto y = 2;
    decltype(x+y) z;

    if (std::is_same<decltype(x),  int>::value) {
        std::cout << "type x == int" << std::endl;
    }
    if (std::is_same<decltype(x), float>::value) {
        std::cout << "type x == float" << std::endl;
    }
    if (std::is_same<decltype(x), decltype(z)>::value) {
        std::cout << "type x == type z" << std::endl;
    }

    //after C++ 11
    auto w = add2<int, double>(1, 2.9);
    if (std::is_same<decltype(w), double>::value) {
        std::cout << "w is double: ";
    }
    std::cout << w << std::endl;

    //after C++ 14
    auto q = add3<double, int>(1.9, 2);
    if (std::is_same<decltype(q), double>::value) {
        std::cout << "q is double: ";
    }
    std::cout << "q: " << q << std::endl;
}