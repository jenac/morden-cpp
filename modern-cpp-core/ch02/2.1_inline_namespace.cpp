#include <iostream>

namespace Parent
{
    namespace Child1
    {
        void foo()
        {
            std::cout << "Child1::foo()" << std::endl;
        }
    }

    inline namespace Child2
    {
        void foo()
        {
            std::cout << "Child2::foo()" << std::endl;
        }
    }
}

void inline_namespace_demo()
{
    std::cout << "-----" << __FUNCTION__ << "-----" << std::endl;
    Parent::Child1::foo();
    Parent::foo();
}

namespace ParentV
{
    namespace V1
    {
        void foo()
        {
            std::cout << "foo v1.0" << std::endl;
        }
    }

    // should have onlye 1 inline
    // should be latest version
    inline namespace V2
    {
        void foo()
        {
            std::cout << "foo v2.0" << std::endl;
        }
    }

}

//nested, simplified
namespace A::B::inline C
{

}

namespace D::inline E::F
{

}

void version_compatibilty_demo()
{
    std::cout << "-----" << __FUNCTION__ << "-----" << std::endl;
    ParentV::foo();
    // to use old version
    ParentV::V1::foo();
}
int main()
{
    inline_namespace_demo();
    version_compatibilty_demo();
}