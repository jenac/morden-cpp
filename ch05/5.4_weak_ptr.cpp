#include <iostream>
#include <memory>

struct A;
struct B;

struct A
{
    std::shared_ptr<B> pointer;
    ~A()
    {
        std::cout << "A is destroyed" << std::endl;
    }
};

struct B
{
    std::shared_ptr<A> pointer;
    ~B()
    {
        std::cout << "B is destoryed" << std::endl;
    }
};

struct WA;
struct WB;

struct WA
{
    std::weak_ptr<WB> pointer;
    ~WA()
    {
        std::cout << "WA is destroyed" << std::endl;
    }
};

struct WB
{
    std::weak_ptr<WA> pointer;
    ~WB()
    {
        std::cout << "WB is destroyed" << std::endl;
    }
};

void shared_issue()
{
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();

    a->pointer = b;
    b->pointer = a;
}

void weak_demo()
{
    auto wa = std::make_shared<WA>();
    auto wb = std::make_shared<WB>();

    wa->pointer = wb;
    wb->pointer = wa;
}

int main()
{
    shared_issue();
    weak_demo();
}
