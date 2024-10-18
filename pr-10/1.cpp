#include <iostream>

template<class T>
void low_budget_swap(T& a, T& b) {
    T _a = a;
    a = b;
    b = _a;
}

int main(int argc, char** argv) {
    double a, b;

    std::cout << "a, b (через пробел): ";
    std::cin >> a >> b;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "swapping..." << std::endl;

    low_budget_swap(a, b);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    return 0;
}
