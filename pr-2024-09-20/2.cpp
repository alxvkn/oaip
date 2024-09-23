#include <iostream>

int main (int argc, char *argv[]) {
    char c = 0;
    unsigned n = 0;

    do {
        std::cin >> c;
        n++;
    } while (c != '.');

    std::cout << n - 1 << std::endl;

    return 0;
}
