#include <iostream>
#include "math_functions.hpp"

int main (int argc, char *argv[]) {
    int a, b;
    std::cout << "a, b (через пробел): ";
    std::cin >> a >> b;

    double division_result;
    bool divisible = true;

    try {
        division_result = divide(a, b);
    } catch (std::exception e) {
        divisible = false;
    }

    std::cout << "add(a, b): " << add(a, b) << std::endl
        << "subtract(a, b): " << subtract(a, b) << std::endl
        << "multiply(a, b): " << multiply(a, b) << std::endl;

    if (divisible)
        std::cout << "divide(a, b): " << division_result << std::endl;

    std::cout << "power(a, b): " << power(a, b) << std::endl
        << "square_root(a): " << square_root(a) << std::endl
        << "factorial(a): " << factorial(a) << std::endl;

    return 0;
}
