#include <array>
#include <climits>
#include <iostream>
#include <random>
#include <vector>

int main (int argc, char *argv[]) {
    int mat[10][10];

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<> distribution(-50, 50);

    for (unsigned i = 0; i < 10; i++) {
        for (unsigned j = 0; j < 10; j++) {
            mat[i][j] = distribution(generator);
            std::cout.width(4);
            std::cout << mat[i][j];
        }
        std::cout << "\n";
    }

    std::array<int, 10> products;

    for (unsigned i = 0; i < 10; i++) {
        int prod = 1;
        for (unsigned j = 0; j < 10; j++) {
            prod *= mat[j][i];
        }
        products[i] = prod;
    }

    int max_prod = products[0];
    for (auto prod : products) {
        if (prod > max_prod)
            max_prod = prod;
    }

    std::cout << "Максимальное произведение столбца: " << max_prod
        << std::endl;


    std::vector<int> divisible_by_five;

    for (unsigned i = 0; i < 10; i++) {
        for (unsigned j = 0; j < 10; j++) {
            int n = mat[i][j];
            if (n % 5 == 0)
                divisible_by_five.push_back(n);
        }
    }

    std::cout << "Элементы, которые кратны 5:";
    for (auto n : divisible_by_five) {
        std::cout << " " << n;
    }
    std::cout << std::endl;

    return 0;
}
