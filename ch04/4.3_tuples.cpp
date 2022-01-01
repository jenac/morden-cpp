#include <tuple>
#include <iostream>
#include <variant>

auto get_student(int id) {
    switch (id)
    {
    case 0:
        return std::make_tuple(3.8, 'A', "Zhang3");
    case 1:
        return std::make_tuple(2.9, 'C', "Li4");
    case 2:
        return std::make_tuple(1.7, 'D', "Wang5");
    default:
        return std::make_tuple(0.0, 'D', "null");
    }
}

//runtime indexing
template <size_t n, typename... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...>& tpl, size_t i) {
    if constexpr (n >= sizeof...(T)) 
        throw std::out_of_range(" .");
    if (i == n)
        return std::variant<T...>{ std::in_place_index<n>, std::get<n>(tpl) };
    return _tuple_index<(n < sizeof...(T)-1 ? n+1 : 0)>(tpl, i); 
}

template <typename... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...>& tpl, size_t i) {
    return _tuple_index<0>(tpl, i); 
}

template <typename T0, typename ... Ts>
std::ostream & operator<< (std::ostream & s, std::variant<T0, Ts...> const & v) {
    std::visit([&](auto && x){ s << x;}, v);
    return s; 
}

//
template <typename T>
auto tuple_len(T &tpl) {
    return std::tuple_size<T>::value;
}

int main() {
    auto s1 = get_student(0);
    std::cout << "id: 0, " 
        << "GAP: " << std::get<0>(s1) << ","
        << "Grade: " << std::get<1>(s1) << ","
        << "Name: " << std::get<0>(s1) << std::endl;

    double gpa;
    char grade;
    std::string name;

    std::tie(gpa, grade, name) = get_student(1);
    std::cout << "id: 1, " 
        << "GAP: " << gpa << ","
        << "Grade: " << grade << ","
        << "Name: " << name << std::endl;

    //tie by type
    std::tuple<std::string, double, double, int> t("123", 4.5, 6.7, 8);
    std::cout << std::get<std::string>(t) << std::endl;
    // std::cout << std::get<double>(t) << std::endl; //compile error
    std::cout << std::get<int>(t) << std::endl;

    //runtime indexing
    int i = 1;
    std::cout << tuple_index(t, i) << std::endl;

    //merge and iteration
    auto new_tuple = std::tuple_cat(get_student(1), std::move(t));

    auto l = tuple_len(new_tuple);
    std::cout << l << std::endl;

    for (int i=0; i<tuple_len(new_tuple); ++i) {
        std::cout << tuple_index(new_tuple, i) << ",";
    }
    std::cout << std::endl;


}