//clang++ 2.5_type_alias_templdates.cpp -std=c++20 -o 2.5_type_alias_templdates
#include <vector>
#include <string>
typedef int (*process)(void*);
using NewProcess = int(*)(void*);

template<typename T, typename U>
class MagicType {
    public:
        T dark;
        U magic;
};

template<typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;

int main() {
    TrueDarkMagic<bool> you;
}