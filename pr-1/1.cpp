#include <iostream>

int main (int argc, char *argv[]) {
    int reverse[4];
    int number;
    std::cin >> number;

    reverse[0] = number % 10;
    reverse[1] = number % 100 / 10;
    reverse[2] = number % 1000 / 100;
    reverse[3] = number % 10000 / 1000;

    std::cout << reverse[0] << reverse[1] << reverse[2] << reverse[3] << std::endl;

    return 0;
}
