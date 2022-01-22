
//delegate constructor
#include <iostream>

class Base
{
public:
    int value1;
    int value2;
    Base()
    {
        value1 = 1;
    }

    Base(int value) : Base()
    { // delegate Base() constructor
        value2 = value;
    }
};

//inheritance constructor
class SubClass : public Base
{
public:
    using Base::Base; //inheritance constructor
};

//Explicit virtual function overwrite
//override
struct BaseOverride
{
    virtual void foo(int);
};

struct SubStructOverride : BaseOverride
{
    virtual void foo(int) override; //legal
    // virtual void foo(float) override; //illegal, no virtual function in super class
};

//final
struct BaseFinal
{
    virtual void foo() final;
};

struct SubStructFinal1 final : BaseFinal
{

}; // legal

// struct SubStructFinal2: SubStructFinal1
// {

// }; // illegal, SubStructFinal1 is final

struct SubStructFinal3 : BaseFinal
{
    // void foo(); //illegal, foo is final
};

//Explicit delete default function
class Magic
{
public:
    Magic() = default;                        // explicit let compiler use default constructor
    Magic &operator=(const Magic &) = delete; //explicit declare refuse constructor
    Magic(int magic_number);
};

//Strongly typed enumerations
enum class new_enum : unsigned int
{
    value1,
    value2,
    value3 = 100,
    value4 = 100
};

//make std::cout << new_enum::value3 << std::endl work
template <typename T>
std::ostream &operator<<(
    typename std::enable_if<std::is_enum<T>::value, std::ostream>::type &stream,
    const T &e)
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

int main()
{
    Base b(2);
    std::cout << b.value1 << ", " << b.value2 << std::endl;

    SubClass s(3);
    std::cout << s.value1 << ", " << s.value2 << std::endl;

    if (new_enum::value3 == new_enum::value4)
    {
        std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
    }
    std::cout << new_enum::value3 << std::endl;
    return 0;
}
