#include <iostream>

int main (int argc, char *argv[]) {
    double a[10];

    for (unsigned i = 0; i < 10; i++) {
        std::cin >> a[i];
    }

    std::cout << "a:";
    for (auto num : a) {
        std::cout << " " << num ;
    }
    std::cout << std::endl;

    a[0] = (a[0] + a[1]) / 2;
    for (unsigned i = 1; i < 9; i++) {
        a[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;
    }
    a[9] = (a[9] + a[8]) / 2;

    std::cout << "a:";
    for (auto num : a) {
        std::cout << " " << num ;
    }
    std::cout << std::endl;

    return 0;
}
