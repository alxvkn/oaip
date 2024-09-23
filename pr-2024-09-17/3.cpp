#include <iostream>

int main (int argc, char *argv[]) {
    unsigned day, month, year;

    std::cout << "Введите цифрами сегодняшнюю дату (число, месяц, год) -> ";
    std::cin >> day >> month >> year;

    int days_in_month = 31;

    if (month >= 6) {

    }

    if (month == 2) {
        if (year % 400 == 0 or (year % 4 == 0 && year % 100 != 0)) {
            days_in_month = 29;
        } else {
            days_in_month = 28;
        }
    } else if (month % 2 == 0) {
        if (month >= 8) {
            days_in_month = 31;
        } else {
            days_in_month = 30;
        }
    }

    if (day > days_in_month or month > 12) {
        std::cout << "Ошибка ввода данных" << std::endl;
        return 1;
    }

    if ((day + 1) > days_in_month) {
        day = 1;
        if ((month + 1) > 12) {
            month = 1;
            year++;
        } else month++;
    } else day++;

    std::cout << day << " " << month << " " << year << std::endl;

    return 0;
}
