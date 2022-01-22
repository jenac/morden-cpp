#include <iostream>
#include <string>

void literal_demo()
{
    std::string str = R"(C:\File\to\
    (how this works?) path)"; // can be multi-line, () is required
    std::cout << str << std::endl;
}

// customize literal
std::string operator"" _wow1(const char *wow1, size_t len)
{
    return std::string(wow1) + "Woooooow, amazing";
}

std::string operator"" _wow2(unsigned long long i)
{
    return std::to_string(i) + "woooow, amazing2";
}

void customize_literal_demo()
{
    auto str = "abc"_wow1;
    auto num = 1_wow2;

    std::cout << str << std::endl;
    std::cout << num << std::endl;
}

int main()
{
    literal_demo();
    std::cout << std::endl
              << std::endl;
    customize_literal_demo();
    return 0;
}