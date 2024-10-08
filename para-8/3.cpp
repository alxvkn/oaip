#include <iostream>

int main (int argc, char *argv[]) {
    double sum = 0;
    int count = 0;

    while (1) {
        double n;
        std::cin >> n;
        sum += n;
        count++;

        char choice;
        std::cout << "Хотите ли вы закончить ввод чисел? (y/n): ";
        std::cin >> choice;

        if (choice == 'Y' or choice == 'y')
            break;
    }

    std::cout << "Сумма чисел: " << sum << std::endl;
    std::cout << "Среднее арифметическое: " << sum / count << std::endl;

    return 0;
}
