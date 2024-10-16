#include <iostream>

unsigned fun(unsigned n) {
    std::cout << n << " ";
    return n == 1 ? 1 : fun(n - 1);
}

int main(int argc, char *argv[]) {
    unsigned n;
    std::cin >> n;

    fun(n);

    std::cout << std::endl;

    return 0;
}
