// clang++ 2.3_auto.cpp -std=c++20 -o 2.3_auto
#include <initializer_list>
#include <vector>
#include <iostream>
#include <typeinfo>

class MagicFoo
{
public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list)
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            vec.push_back(*it);
        }
    }
};

// after C++ 20
int add(auto x, auto y)
{
    return x + y;
}

int main()
{
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    std::cout << "magicFoo: ";
    for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    auto i = 5;
    auto arr = new auto(10); //arr become int*
    std::cout << typeid(i).name() << std::endl;
    std::cout << typeid(arr).name() << std::endl;

    auto j = 6;
    std::cout << add(i, j) << std::endl;
    return 0;
}