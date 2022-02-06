void rule_1()
{
    const int i = 5;
    auto j = i;  // auto is int, not const int
    auto &m = i; // auto is const int, m is const int&
    // ariable 'k' with type 'auto *' has incompatible initializer of type 'const int'
    // auto *k = i;      // auto is const int, k is const int*
    const auto n = j; // auto is int n is const int
}

void rule_2()
{
    int i = 5;
    int &j = i;
    auto m = j; // auto is int, not int &
}

void rule_3()
{
    int i = 5;
    auto &&m = i; // auto is int&
    auto &&j = 5; // auto is int
}

int sum(int a1, int a2)
{
    return a1 + a2;
}

void rule_4()
{
    int i[5];
    auto m = i;   // auto is int*
    auto j = sum; // auto is int (__cdecl *) (int, int)
}

int main()
{
    rule_1();
    rule_2();
}