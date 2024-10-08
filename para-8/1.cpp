#include <iostream>

int main (int argc, char *argv[]) {
    unsigned a;
    std::cout << "Введите предел: ";
    std::cin >> a;

    for (unsigned i = 1; i < a; i += 2) {
        std::cout << i << "² = " << i * i << "\n";
    }

    return 0;
}
