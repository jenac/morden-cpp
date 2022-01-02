#include <vector>
#include <string>
#include <iostream>
// string literal
class Foo
{
    // here string literal is rvalue
    const char *&&right = "this is a rvalue";

public:
    void bar()
    {
        // still rvalue
        right = "still rvalue";
    }
};

// xvalue
std::vector<int> foo()
{
    std::vector<int> temp = {1, 2, 3, 4};
    // return temp will cause copy and overhead.
    // in C++11, compiler will implicit convert lvalue temp to rvalue,
    // like static_cast<std::vector<int> &&>(temp)
    return temp;
}

//rvalue reference and lvalue reference
void reference(std::string &str)
{
    std::cout << " lvalue" << std::endl;
}

void reference(std::string &&str)
{
    std::cout << " rvalue" << std::endl;
}

int main()
{
    std::vector<int> v = foo();

    // here string literal is lvalue
    const char *const &left = "this is an lvalue";

    std::string lv1 = "string,"; //lv1 is a lvalue
    // std::string&& r1 = lv1; // illegal, rvalue can't ref to lvalue
    std::string &&rv1 = std::move(lv1); // legal, std::move can convert lvalue to rvalue
    std::cout << rv1 << std::endl;

    const std::string &lv2 = lv1 + lv1; // legal, const lvalue can extend temp variable's lifetime
    // lv2 += "Test"; // illegal, const ref can't be modified
    std::cout << lv2 << std::endl;

    std::string &&rv2 = lv1 + lv2; // legal, rvalue ref extend lifcycle
    rv2 += "string";               // legal, non-const reference can be modified
    std::cout << rv2 << std::endl;

    // some points
    // int& a = std::move(1); //illegal, non-const lvalue reference cannot ref rvalue
    const int &b = std::move(1); //legal, const lvalue can, because Fortran need it??

    reference(rv2);
}
