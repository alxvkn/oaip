#include <iostream>

#define DAYS_IN_YEAR 365
#define DAYS_IN_MONTH 30
#define RATE (double)5

double percentage_per_month(double deposit) {
    return (deposit * (RATE / 100) / DAYS_IN_YEAR * DAYS_IN_MONTH);
}

int main (int argc, char *argv[]) {
    int months;
    double deposit;

    std::cout << "Введите сумму депозита: ";
    std::cin >> deposit;

    std::cout << "Введите количество месяцев: ";
    std::cin >> months;

    std::cout << deposit + percentage_per_month(deposit) * months;

    return 0;
}
