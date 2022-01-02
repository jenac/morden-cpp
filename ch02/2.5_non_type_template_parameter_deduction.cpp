#include <iostream>
// type template parameter
template <typename T, typename U>
auto add(T t, U u)
{
    return t + u;
}

// non-type template parameter
template <typename T, int BufSize>
class buffer_t
{
public:
    T &alloc();
    void free(T &item);

private:
    T data[BufSize];
};

//usage:
buffer_t<int, 100> buf;

template <auto value>
void foo()
{
    std::cout << value << std::endl;
}

int main()
{
    foo<1001>();
}