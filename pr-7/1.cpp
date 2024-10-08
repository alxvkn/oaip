#include <iostream>
#include <set>

double sum(const std::set<double>& s) {
    double _sum = 0;

    for (auto e : s) {
        _sum += e;
    }

    return _sum;
}

double avg(const std::set<double>& s) {
    return sum(s) / s.size();
}

int main (int argc, char *argv[]) {
    std::set<double> s;
    int choice = -1;

    while (choice != 0) {
        std::cout << "\nЧто вы хотите сделать:\n"
            << "1) добавить число\n"
            << "2) просмотреть введённые числа\n"
            << "3) вывести сумму чисел\n"
            << "4) вывести среднее чисел\n"
            << "5) удалить число\n"
            << "0) выйти" << std::endl;

        std::cin >> choice;

        double a;

        switch (choice) {
            case 1:
                std::cout << "Введите число, которое вы хотите добавить: ";
                std::cin >> a;
                s.insert(a);
                break;
            case 2:
                std::cout << "Числа:";
                for (auto e : s) {
                    std::cout << " " << e;
                }
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "Сумма чисел: " << sum(s) << std::endl;
                break;
            case 4:
                std::cout << "Среднее чисел: " << avg(s) << std::endl;
                break;
            case 5:
                std::cout << "Введите число, которое вы хотите удалить: ";
                std::cin >> a;
                s.erase(a);
                break;
            case 0:
                return 0;
                break;
        }
    }

    return 0;
}
