#include <iostream>
#include <utility>

void reference(int &v)
{
    std::cout << "lvalue reference" << std::endl;
}

void reference(int &&v)
{
    std::cout << "rvalue reference" << std::endl;
}

template <typename T>
void pass(T &&v)
{
    std::cout << " normal param passing: ";
    reference(v);
}

template <typename T>
void pass_better(T &&v)
{
    std::cout << " normal param passing: ";
    reference(v);

    std::cout << " std::move param passing: ";
    reference(std::move(v));

    std::cout << " std::forward param passing: ";
    reference(std::forward<T>(v));

    std::cout << " static_cast<T&&> param passing: ";
    reference(static_cast<T &&>(v));
}

int main()
{
    // the issue and reference collapse rule
    std::cout << "rvalue pass:" << std::endl;
    pass(1);
    std::cout << "lvalue pass:" << std::endl;
    int l = 1;
    pass(l);

    std::cout << "-----pass_better-----" << std::endl;
    std::cout << "rvalue pass:" << std::endl;
    pass_better(1);
    std::cout << "lvalue pass:" << std::endl;
    // int l = 1;
    pass_better(l);

    return 0;
}