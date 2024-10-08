#include <iostream>

int main (int argc, char *argv[]) {
    int arr[4];

    std::cout << "Введите 4 числа:" << std::endl;

    for (unsigned i = 0; i < 4; i++) {
        std::cin >> arr[i];
    }

    for (unsigned i = 0; i < 4; i++) {
        std::cout << arr[3 - i] << std::endl;
    }

    return 0;
}
