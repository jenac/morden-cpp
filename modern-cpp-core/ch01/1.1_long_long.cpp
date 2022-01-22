#include <iostream>
#include <limits>
#include <cstdio>

void long_long_demo_A()
{
    std::cout << "-----" << __FUNCTION__ << "-----" << std::endl;
    long long x1 = 65536 << 16;
    std::cout << "x1 = " << x1 << std::endl;

    long long x2 = 65536LL << 16;
    std::cout << "x2 = " << x2 << std::endl;
}

void long_long_demo_B()
{
    std::cout << "-----" << __FUNCTION__ << "-----" << std::endl;
    enum longlong_enum : long long
    {
        x1,
        x2
    };

    struct longlong_struct
    {
        long long x1 : 8;
        long long x2 : 24;
        long long x3 : 32;
    };

    std::cout << sizeof(longlong_enum::x1) << std::endl;
    std::cout << sizeof(longlong_struct) << std::endl;
}

void long_long_demo_C()
{
    std::cout << "-----" << __FUNCTION__ << "-----" << std::endl;
    // use macro
    std::cout << "LLONG_MAX = " << LLONG_MAX << std::endl;
    std::cout << "LLONG_MIN = " << LLONG_MIN << std::endl;
    std::cout << "ULLONG_MAX = " << ULLONG_MAX << std::endl;

    // use template
    std::cout << "std::numeric_limits<long long>::max() = " << 
        std::numeric_limits<long long>::max() << std::endl;
    std::cout << "std::numeric_limits<long long>::min() = " << 
        std::numeric_limits<long long>::min() << std::endl;
    std::cout << "std::numeric_limits<unsigned long long>::max() = " << 
        std::numeric_limits<unsigned long long>::max() << std::endl;
}

int main()
{
    long_long_demo_A();
    long_long_demo_B();
    long_long_demo_C();
    return 0;
}