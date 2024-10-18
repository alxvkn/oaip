#include <iostream>

bool is_even(int n) {
    return n % 2 == 0;
}

unsigned factorial(unsigned n) {
    return n <= 1 ? n : n * factorial(n - 1);
}

int main (int argc, char *argv[]) {
    unsigned n;
    std::cin >> n;

    if (is_even(n)) {
        std::cout << factorial(n) << std::endl;
    } else {
        std::cout << "Число не подходит." << std::endl;
    }

    return 0;
}
