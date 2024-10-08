#include <iostream>

int main (int argc, char *argv[]) {
    int arr[16];

    for (unsigned i = 0; i < 16; i++) {
        arr[i] = i * 2 + 1;
    }

    for (unsigned i = 0; i < 16; i++) {
        std::cout << arr[15 - i] << std::endl;
    }

    return 0;
}
