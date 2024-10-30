#include <climits>
#include <iostream>
#include <vector>

std::vector<int> flatten_matrix(std::vector<std::vector<int>>& arr) {
    std::vector<int> ret;

    for (auto _arr : arr) {
        for (auto a : _arr) {
            ret.push_back(a);
        }
    }

    return std::move(ret);
}

int main (int argc, char *argv[]) {
    unsigned m, n;
    std::cout << "Введите размер матрицы (строки, столбцы через пробел): ";
    std::cin >> m >> n;

    std::vector<std::vector<int>> v;

    for (size_t i = 0; i < m; i++) {
        std::cout << "Строка #" << i + 1 << std::endl;
        std::vector<int> row;

        for (size_t j = 0; j < n; j++) {
            int a;
            std::cin >> a;
            row.push_back(a);
        }

        v.push_back(row);
    }

    std::vector<int> v_flat = flatten_matrix(v);

    for (int a : v_flat) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    return 0;
}
