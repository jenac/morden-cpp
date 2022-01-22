#include <iostream>
#include <functional>

// alias, function pointer
using foo = void(int);
void functionalA(foo f)
{
    f(1);
}

int fooFunc(int para)
{
    return para;
}

// with C++ 11 std::function
// std::function wraps a function that take int paramter and return int value
void demo_std_function()
{
    std::cout << "-----demo_std_function-----" << std::endl;
    std::function<int(int)> func = fooFunc;

    int important = 100;
    std::function<int(int)> func2 = [&](int value) -> int
    {
        return 1 + value + important;
    };

    std::cout << func(10) << std::endl;
    std::cout << func2(10) << std::endl;
}

// std::bind and std::place holder

int fooFunc2(int a, int b, int c)
{
    std::cout << a << ", " << b << ", " << c << std::endl;
    return 0;
}

void demo_bind_and_placeholder()
{
    std::cout << "-----demo_std_function-----" << std::endl;
    // bind parameter 1, 2 on function fooFunc2,
    // and use std::placehoders::_1 as placeholder for the first parameter
    auto bindFoo = std::bind(fooFunc2, std::placeholders::_1, 1, 2);
    bindFoo(1);
}
int main()
{
    auto f = [](int value)
    {
        std::cout << value << std::endl;
    };
    // call by function pointer
    functionalA(f);
    // call by lambda
    f(1);

    demo_std_function();
    demo_bind_and_placeholder();
    return 0;
}
