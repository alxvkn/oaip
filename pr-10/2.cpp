#include <iostream>

bool is_even(int n) {
    return n % 2 == 0;
}

int main (int argc, char *argv[]) {
    int n;
    std::cin >> n;
    std::cout << std::boolalpha << is_even(n) << std::endl;
    return 0;
}
