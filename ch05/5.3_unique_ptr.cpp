#include <iostream>
#include <memory>

struct Foo
{
    Foo() { std::cout << "Foo::Foo" << std::endl; }
    ~Foo() { std::cout << "Foo::~Foo" << std::endl; }
    void foo() { std::cout << "Foo::foo" << std::endl; }
};

void f(const Foo &) {
    std::cout << "f(const Foo &)" << std::endl;
}


int main()
{
    std::unique_ptr<int> pointer = std::make_unique<int>(10);
    // std::unique_ptr<int> pointer2 = pointer; // illegal

    std::unique_ptr<Foo> p1(std::make_unique<Foo>());

    std::cout << "p1 is not empty, prints | "  << std::endl;
    if (p1) p1->foo();
    std::cout << " |"  << std::endl << std::endl;

    {
        std::unique_ptr<Foo> p2(std::move(p1));

        f(*p2);

        std::cout << "p2 is not empty, prints | "  << std::endl;
        if (p2) p2->foo();
        std::cout << " |"  << std::endl << std::endl;

        std::cout << "p1 empty, no prints | "  << std::endl;
        if (p1) p1->foo();
        std::cout << " |"  << std::endl << std::endl;

        p1 = std::move(p2);

        std::cout << "p1 empty, no prints | "  << std::endl;
        if (p2) p2->foo();
        std::cout << " |"  << std::endl << std::endl;

        std::cout << "p2 was destroyed" << std::endl;
    }

    std::cout << "p1 is not empty, prints | "  << std::endl;
    if (p1) p1->foo();
    std::cout << " |"  << std::endl << std::endl;
    // Foo instance will be destroyed when leaving the scope
}