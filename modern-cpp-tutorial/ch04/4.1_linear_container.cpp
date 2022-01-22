#include <iostream>
#include <vector>
#include <array>

void foo(int *p, int len)
{
    std::cout << "simulate c code" << std::endl;
    std::cout << *p << std::endl;
}

//vector: capacity, shrink_to_fit
void vector_demo()
{
    std::cout << "-----vecotr_demo-----" << std::endl;
    std::vector<int> v;
    std::cout << "vector size: " << v.size() << std::endl;
    std::cout << "vector capacity: " << v.capacity() << std::endl;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::cout << "vector size: " << v.size() << std::endl;
    std::cout << "vector capacity: " << v.capacity() << std::endl;

    v.push_back(4);
    v.push_back(5);
    std::cout << "vector size: " << v.size() << std::endl;
    std::cout << "vector capacity: " << v.capacity() << std::endl;

    v.clear();
    std::cout << "vector size: " << v.size() << std::endl;
    std::cout << "vector capacity: " << v.capacity() << std::endl;

    v.shrink_to_fit();
    std::cout << "vector size: " << v.size() << std::endl;
    std::cout << "vector capacity: " << v.capacity() << std::endl;
}

void array_demo()
{
    std::cout << "-----array_demo-----" << std::endl;
    std::array<int, 4> arr = {2, 3, 1, 4};
    std::array<int, 0> arrb;
    std::cout << arr.empty() << std::endl;
    std::cout << arrb.empty() << std::endl;

    std::cout << arr.size() << std::endl;
    for (auto &i : arr)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    std::sort(arr.begin(), arr.end(), [](int a, int b)
              { return b < a; });
    for (auto &i : arr)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    //using constexpr define size
    constexpr int len = 2 * 2;
    std::array<int, len> arr2 = {1, 2, 3, 4};
    std::cout << arr2.size() << std::endl;

    //illegal, not like c array, std::array cannot be T*
    // int* arr_p = arr;

    //to adapt with the above C code, see void (int*p, int len):
    foo(&arr[2], arr.size());
}

int main()
{
    vector_demo();
    array_demo();
}