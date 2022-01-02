//clang++ 2.2_initializer.cpp -std=c++17 -o 2.2_initializer
#include <iostream>
#include <vector>
#include <initializer_list>
class Foo
{
public:
    int value_a;
    int value_b;

    Foo(int a, int b) : value_a(a), value_b(b) {}
};

class MagicFoo
{
public:
    std::vector<int> vec;

    MagicFoo(std::initializer_list<int> list)
    {
        for (std::initializer_list<int>::iterator it = list.begin(); it != list.end(); ++it)
        {
            vec.push_back(*it);
        }
    }

    void foo(std::initializer_list<int> list)
    {
        for (std::initializer_list<int>::iterator it = list.begin(); it != list.end(); ++it)
        {
            vec.push_back(*it);
        }
    }
};

void print(MagicFoo magicFoo)
{
    std::cout << "magicFoo: ";
    for (std::vector<int>::iterator it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it)
    {
        std::cout << *it << ",";
    }
    std::cout << std::endl;
}

int main()
{

    //brfore C++ 11
    int arr[3] = {1, 2, 3};
    Foo foo(1, 2);
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::cout << "arr[0]: " << arr[0] << std::endl;
    std::cout << "foo: " << foo.value_a << "," << foo.value_b << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    //after C++ 11
    std::cout << "C++ 11 has initializer_list" << std::endl;
    MagicFoo magicFoo = {2, 3, 4, 5, 6, 7};
    print(magicFoo);

    magicFoo.foo({101, 102, 102});
    print(magicFoo);

    MagicFoo magicFoo2({100, 200, 300});
    print(magicFoo2);

    return 0;
}
