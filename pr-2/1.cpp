#include <iostream>

int main (int argc, char *argv[]) {
    unsigned n;
    std::cout << "Введите номер месяца: ";
    std::cin >> n;

    std::cout << "Время года: ";

    switch (n) {
        case 12:
        case 1:
        case 2:
            std::cout << "зима";
            break;
        case 3:
        case 4:
        case 5:
            std::cout << "весна";
            break;
        case 6:
        case 7:
        case 8:
            std::cout << "лето";
            break;
        case 9:
        case 10:
        case 11:
            std::cout << "осень";
            break;
        default:
            std::cout << "ошибка ввода данных";
    }

    std::cout << "." << std::endl;

    return 0;
}
