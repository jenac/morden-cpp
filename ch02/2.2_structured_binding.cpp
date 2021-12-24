//clang++ 2.2_structured_binding.cpp -std=c++17 -o 2.2_structured_binding
#include <iostream>
#include <tuple>
//C++ 17 has
std::tuple<int, double, std::string> f() {
    return std::make_tuple(1, 2.3, "456");
}

int main() {
    auto [x, y, z] = f();
    std::cout << x << ", " << y << ", " << z << std::endl;
    return 0;
}