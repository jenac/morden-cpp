#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> i)
{
    (*i)++;
}

void basics()
{
    std::cout << "-----basics-----" << std::endl;
    auto pointer = new int(10);
    std::cout << pointer << "=" << *pointer << std::endl;
    delete pointer;

    // constructed a std::shared_ptr
    auto sp = std::make_shared<int>(10);
    foo(sp);
    std::cout << sp << "(" << sp.get() << ")"
              << "=" << *sp << std::endl;
    // the shared_ptr will be desctructed before leaving the scope
}

void count_demo()
{
    std::cout << "-----count_demo-----" << std::endl;
    auto pointer = std::make_shared<int>(10);
    auto pointer2 = pointer; // reference count + 1
    auto pointer3 = pointer; // reference count + 2
    int *p = pointer.get();  // no increase for reference count
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;

    pointer2.reset();
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;

    pointer3.reset();
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;
}

int main()
{
    basics();
    count_demo();
}