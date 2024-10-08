#include <iostream>

int main (int argc, char *argv[]) {
    const unsigned current_year = 2024;

    unsigned birth_year;
    std::string fio;

    std::cout << "Введите ваше ФИО: ";
    std::getline(std::cin, fio);
    // std::cin >> fio;

    std::cout << "Введите ваш год рождения: ";
    std::cin >> birth_year;

    std::cout << "Ваше ФИО: " << fio << std::endl;
    std::cout << "Ваш возраст: " << current_year - birth_year << std::endl;

    return 0;
}
