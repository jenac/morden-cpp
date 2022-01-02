#include <iostream>
#include <string>
#include <vector>

class A
{
public:
    int *pointer;
    A() : pointer(new int(1))
    {
        std::cout << " construct" << pointer << std::endl;
    }

    A(A &a) : pointer(new int(*a.pointer))
    {
        std::cout << " copy" << pointer << std::endl;
    }

    A(A &&a) : pointer(a.pointer)
    {
        a.pointer = nullptr;
        std::cout << " move" << pointer << std::endl;
    }

    ~A()
    {
        std::cout << " destruct" << pointer << std::endl;
        delete pointer;
    }
};

A return_rvalue(bool test)
{
    A a, b;
    if (test)
    {
        return a; // same as static_cast<A&&>(a)
    }
    else
    {
        return b; // same as static_cast<A&&>(b)
    }
}

void move_demo()
{
    std::cout << "-----move_demo-----" << std::endl;
    A obj = return_rvalue(false);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;
}

void move_demo_std()
{
    std::cout << "-----move_demo_std-----" << std::endl;
    std::string str = "Hello, World!";
    std::vector<std::string> vs;

    vs.push_back(str); // will cause copy
    std::cout << "str: " << str << std::endl;

    // push_back(const & T&&) will not cause copy
    vs.push_back(std::move(str));
    std::cout << "str: " << str << std::endl;
}

int main()
{
    // move
    move_demo();

    //move with std
    move_demo_std();

    return 0;
}