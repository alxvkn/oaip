#include <iostream>
#include <random>

#define LENGTH 21

int main (int argc, char *argv[]) {
    int a[LENGTH];
    int b[LENGTH];
    int c[LENGTH];

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<> distribution(10, 30);

    for (unsigned i = 0; i < LENGTH; i++) {
        a[i] = distribution(generator);
        b[i] = distribution(generator);
        c[i] = a[i] + b[i];
    }

    std::cout << "a:";
    for (unsigned i = 0; i < LENGTH; i++) {
        std::cout << " " << a[i];
    }
    std::cout << std::endl;

    std::cout << "b:";
    for (unsigned i = 0; i < LENGTH; i++) {
        std::cout << " " << b[i];
    }
    std::cout << std::endl;

    std::cout << "c:";
    for (unsigned i = 0; i < LENGTH; i++) {
        std::cout << " " << c[i];
    }
    std::cout << std::endl;

    double sum = 0;
    int min = c[0], max = c[0];
    for (unsigned i = 0; i < LENGTH; i++) {
        sum += c[i];
        if (c[i] > max)
            max = c[i];
        if (c[i] < min)
            min = c[i];
    }

    std::cout << "Среднее арифметическое: " << sum / LENGTH << std::endl;
    std::cout << "Минимальное: " << min << std::endl;
    std::cout << "Максимальное: " << max << std::endl;

    return 0;
}
