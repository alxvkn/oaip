#include <iostream>

// В России выйдет православный мессенджер

int main (int argc, char *argv[]) {
    double m, p, k;

    std::cout << "Введите M: ";
    std::cin >> m;

    std::cout << "Введите P: ";
    std::cin >> p;

    std::cout << "Введите K: ";
    std::cin >> k;

    double norm_prev = m;
    unsigned day = 1;

    double norm = norm_prev;

    while (norm <= k) {
        norm = norm_prev * (1 + (p / 100));
        norm_prev = norm;
        day++;
    }

    std::cout << "В день " << day << std::endl;

    return 0;
}
