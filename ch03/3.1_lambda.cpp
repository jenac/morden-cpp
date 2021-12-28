#include <iostream>
#include <memory> // std::make_unique
#include <utility> // std::move
//basics
// [capture list] (parameter list) mutable(optional) exception attribute -> return type {
//     function body
// }

// value capture
void lambda_value_capture() {
    std::cout << "-----lambda_value_capture-----" << std::endl;
    int value = 1;
    auto copy_value = [value] {
        return value;
    };
    value = 100;
    auto store_value = copy_value();
    std::cout << "store value = " << store_value << std::endl;
    // at this moment, stored_value == 1, and value == 100.
    // since copy_value has copied when it was created
}

// reference capture
void lambda_reference_capture() {
    std::cout << "-----lambda_reference_capture-----" << std::endl;
    int value = 1;
    auto copy_value = [&value] {
        return value;
    };
    value = 100;
    auto store_value = copy_value();
    std::cout << "store value = " << store_value << std::endl;
    // at this moment, sotre_value == 100, value == 100
    // since copy_value stores the reference
}

// Implicit capture
// [] empty capture list
// [name1, name2, ...] captures a series of variables
// [&] reference capture, let compiler deduce the reference list by itself
// [=] value capture, let compiler deduce the value list by itself

// Expression capture
// use it capture rvalue reference
// here important is an exclusive pointer that cannot be captured by value.
// we can transfer it to rvalue and init it in expression
void lambda_expression_capture() {
    std::cout << "-----lambda_expression_capture-----" << std::endl;
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)] (int x, int y) -> int {
        return x+y+v1+(*v2);
    };
    std::cout << add(3,4) << std::endl;
}

// generic lambda
// lambda can use auto
void generic_lambda() {
    std::cout << "-----generic_lambda-----" << std::endl;
    auto add = [](auto x, auto y) {
        return x+y;
    };
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.1, 2.2) << std::endl;
}


int main() {
    lambda_value_capture();
    std::cout << std::endl;
    lambda_reference_capture();
    std::cout << std::endl;
    lambda_expression_capture();
    std::cout << std::endl;
    generic_lambda();
    std::cout << std::endl;
}