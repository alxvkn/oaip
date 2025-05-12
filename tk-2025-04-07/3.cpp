#include <iostream>
#include <ctime>

int main (int argc, char *argv[]) {
    unsigned year, month, day;

    std::cout << "Введите через пробел год, месяц, число: ";
    std::cin >> year >> month >> day;

    struct std::tm dt = { 0 };
    dt.tm_year = year - 1900;
    dt.tm_mon = month - 1;
    dt.tm_mday = day;

    mktime(&dt);

    int wday = dt.tm_wday;

    std::string wday_string[] = {
        "Воскресенье",
        "Понедельник",
        "Вторник",
        "Среда",
        "Четверг",
        "Пятница",
        "Суббота",
    };

    std::cout << wday_string[wday] << std::endl;

    return 0;
}
