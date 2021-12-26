#include <iostream>
#include <initializer_list>

template<typename... Ts>
void magic(Ts... args) {
    std::cout << sizeof...(args) << std::endl;
}


// recursice
template<typename T0>
void printf1(T0 value) {
    std::cout << value << std::endl;
}

template<typename T, typename... Ts>
void printf1(T value, Ts... args) {
    std::cout << value << std::endl;
    printf1(args...);
}

//Variable parameter template expansion
template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
    std::cout << t0 << std::endl;
    if constexpr (sizeof...(t) > 0) { 
        printf2(t...);
    }
}

//Initialize list expansion
template<typename T, typename... Ts>
auto printf3(T value, Ts... args) {
    std::cout << value << std::endl;
    (void) std::initializer_list<T>{([&args]{
        std::cout << args << std::endl;
    }(), value)...};
}

int main() {
    magic();
    magic(1);
    magic(1,2,"", "how", "are", "you", "?");

    std::cout << "----- recursive -----" << std::endl;
    printf1(1, 2, "123", 1.1);
    
    std::cout << "----- variable parameter template expansion -----" << std::endl;
    printf2(2, 22, "222", 2.2);

    std::cout << "----- initialize list expansion -----" << std::endl;
    printf3(3, 33, "333", 3.3);

    return 0;
}