// does not compile, just for example
#include <string>

std::string lookup1();
const std::string& cc = "cc";
std::string& lookup2();

decltype(auto) lookup_a_string_1() {
    return lookup1();
}

decltype(auto) lookup_a_string_2() {
    return lookup2();
}