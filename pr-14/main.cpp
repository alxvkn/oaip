#include <ios>
#include <iostream>

import m;

int main() {
    unsigned n;
    std::cin >> n;
    std::cout << "Число чётное: " << std::boolalpha << m::is_even(n) << std::endl
        << "Число начинается с секретной цифры: " << std::boolalpha
        << m::starts_with_secret_digit(n) << std::endl
        << "Число кончается секретной цифрой: " << std::boolalpha
        << m::ends_with_secret_digit(n) << std::endl
        << "Факториал числа: " << m::factorial(n) << std::endl;
    
}
