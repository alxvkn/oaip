#include <iostream>
#include <set>

int main (int argc, char *argv[]) {
    unsigned n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    int arr[n];

    for (unsigned i = 0; i < n; i++) {
        int e;
        std::cin >> e;
        arr[i] = e;
    }

    char choice;
    std::cout << "Оставить ли повторные числа? [y/n]: ";
    std::cin >> choice;

    if (choice == 'y') {
        std::multiset<int> m;
        for (auto e : arr) {
            m.insert(e);
        }
        for (auto e : m) {
            std::cout << e << " ";
        }
    } else {
        std::set<int> m;
        for (auto e : arr) {
            m.insert(e);
        }
        for (auto e : m) {
            std::cout << e << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
