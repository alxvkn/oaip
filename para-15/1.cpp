#include <climits>
#include <iostream>
#include <vector>
#include <random>

std::vector<int> find_odd_numbers(std::vector<int>& arr) {
    std::vector<int> ret;

    for (int a : arr) {
        if (a % 2 != 0)
            ret.push_back(a);
    }

    return std::move(ret);
}

int main (int argc, char *argv[]) {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<> distribution(INT_MIN, INT_MAX);

    unsigned len;
    std::cin >> len;

    std::vector<int> v;
    v.reserve(len);

    for (size_t i = 0; i < len; i++) {
        v.push_back(distribution(generator));
    }

    for (int a : v) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    auto v_odds = find_odd_numbers(v);

    for (int a : v_odds) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    return 0;
}
