#include <iostream>

int main (int argc, char *argv[]) {
    size_t n;
    std::cin >> n;

    int* arr = new int[n];

    for (unsigned i = 0; i < n; i++) {
        *(arr + i) = i * i;
    }

    for (unsigned i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    unsigned sum = 0;
    for (unsigned i = 0; i < n; i++) {
        sum += arr[i];
    }

    std::cout << sum << std::endl;

    return 0;
}
