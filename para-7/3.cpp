#include <iostream>

int main (void) {
    int day;
    std::cout << "Введите номер дня недели: ";
    std::cin >> day;

    std::cout << "Это ";

    switch (day) {
        case 1:
            std::cout << "понедельник";
            break;
        case 2:
            std::cout << "вторник";
            break;
        case 3:
            std::cout << "среда";
            break;
        case 4:
            std::cout << "четверг";
            break;
        case 5:
            std::cout << "пятница";
            break;
        case 6:
            std::cout << "суббота";
            break;
        case 7:
            std::cout << "воскресенье";
            break;
        default:
            std::cout << "неверный номер дня недели";
            break;
    }
    std::cout << "." << std::endl;

    return 0;
}
