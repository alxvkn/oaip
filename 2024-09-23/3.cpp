#include <algorithm>
#include <iostream>
#include <vector>

int main (int argc, char *argv[]) {
    std::vector<int> vec;
    unsigned n = 0;

    std::cout << "Введите длину массива: ";
    std::cin >> n;

    std::cout << "Вводите числа:" << std::endl;

    for (unsigned i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        vec.push_back(a);
    }

    std::sort(vec.begin(), vec.end());

    for (auto a : vec) {
        std::cout << a << std::endl;
    }

    return 0;
}
