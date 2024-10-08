#include <iostream>

int main (int argc, char *argv[]) {
    unsigned time_minutes, day;
    double cost, cost_per_minute = 5.52, discount = 0;
    std::cout << "Введите исходные данные:" << std::endl
        << "Длительность разговора (целое количество минут) -> ";
    std::cin >> time_minutes;

    std::cout << "День недели -> ";
    std::cin >> day;

    switch (day) {
        case 6:
        case 7:
            discount = 0.2;
            break;
    }

    cost = (cost_per_minute * time_minutes);
    std::cout << "Стоимость разговора: " << cost - (discount * cost)
        << std::endl;

    return 0;
}
