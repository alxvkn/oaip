#include <iostream>

int main (int argc, char *argv[]) {
    double d, fuel_per_100_km, fuel_price;

    std::cout << "Введите расстояние до дачи: ";
    std::cin >> d;
    std::cout << "Введите расход на 100км: ";
    std::cin >> fuel_per_100_km;
    std::cout << "Введите цену на литр бензина: ";
    std::cin >> fuel_price;

    std::cout << "Стоимость поездки: " << ((d * 2) / 100) * fuel_per_100_km * fuel_price;

    return 0;
}
