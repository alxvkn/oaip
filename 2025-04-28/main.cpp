#include <cstdlib>
#include <iostream>
#include <array>

int main (int argc, char** argv) {
    std::array<int, 3> S = {20, 30, 25};
    std::array<int, 4> C = {10, 25, 30, 10};

    const std::array<int, 12> costs = {
        8, 6, 10, 9,
        9, 7, 4, 2,
        3, 4, 2, 5,
    };

    int total_cost = 0;

    uint S_index = 0;
    uint C_index = 0;

    while (C[C_index] != 0 || S[S_index] != 0 && C_index < C.size() && S_index < S.size()) {

        std::cout << "S_index: " << S_index << std::endl;
        std::cout << "C_index: " << C_index << std::endl;

        std::cout << "S: " << S[S_index] << std::endl;
        std::cout << "C: " << C[C_index] << std::endl;

        int d = S[S_index] - C[C_index];

        std::cout << "d: " << d << std::endl;
        int cost = costs[S_index * C.size() + C_index] * (d <= 0 ? S[S_index] : C[C_index]);
        std::cout << "cost: " << cost << std::endl;

        total_cost += cost;
        std::cout << "total_cost: " << total_cost << std::endl;
        std::cout << std::endl;


        if (d < 0) {
            C[C_index] = -d;
            S[S_index] = 0;
            S_index++;
        } else if (d == 0) {
            S[S_index] = d;
            C[C_index] = -d;
            S_index++;
            C_index++;
        } else {
            S[S_index] = d;
            C[C_index] = 0;
            C_index++;
        }
    }

    std::cout << total_cost << std::endl;

    return 0;
}
