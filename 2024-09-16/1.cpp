#include <iostream>

int main(void) {
    double cost, discount;

    std::cout << "Введите стоимость покупки: ";
    std::cin >> cost;

    discount = (cost > 500 ? (cost > 1000 ? 0.05 : 0.03) : 0);

    return 0;
}
