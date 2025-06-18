#include <chrono>
#include <iostream>

std::chrono::year_month_day ask_date() {
    using namespace std::chrono;

    int _day, _month, _year;

    std::cout << "Введите день: ";
    std::cin >> _day;
    std::cout << "Введите месяц (1-12): ";
    std::cin >> _month;
    std::cout << "Введите год (гггг): ";
    std::cin >> _year;

    day d(_day);
    month m(_month);
    year y(_year);

    return std::chrono::year_month_day(y, m, d);
}

int main (int argc, char **argv) {
    using namespace std::chrono;

    std::cout << "Первая дата" << std::endl;
    auto first = time_point<system_clock, days>(ask_date());
    std::cout << std::endl;

    std::cout << "Вторая дата" << std::endl;
    auto second = time_point<system_clock, days>(ask_date());
    std::cout << std::endl;

    std::cout << duration_cast<days>(second - first) << std::endl;
    std::cout << duration_cast<hours>(second - first) << std::endl;
    std::cout << duration_cast<minutes>(second - first) << std::endl;

    return 0;
}
