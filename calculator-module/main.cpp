#include <iostream>

import calculator;

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << "calculator::add(a, b) = " << calculator::add(a, b) << std::endl;
    std::cout << "calculator::sub(a, b) = " << calculator::sub(a, b) << std::endl;
    std::cout << "calculator::mul(a, b) = " << calculator::mul(a, b) << std::endl;
    std::cout << "calculator::div(a, b) = " << calculator::div(a, b) << std::endl;
    std::cout << "calculator::pow(a, b) = " << calculator::pow(a, b) << std::endl;
}
