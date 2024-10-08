#include <iostream>
#include <map>

int main (int argc, char *argv[]) {
    std::map<std::string, double> prices;

    int choice = -1;

    while (choice != 0) {
        std::cout << "\nВыберите действие:\n"
            << "1. Просмотреть цены\n"
            << "2. Добавить продукт\n"
            << "3. Изменить цену\n"
            << "0. Выйти" << std::endl;

        std::cin >> choice;

        switch (choice) {
            case 1:
                for (auto p : prices) {
                    std::cout << p.first << ": " << p.second << "\n";
                }
            break;
            case 2:
            case 3:
                std::string item;
                double price;
                std::cout << "Название продукта и цена (через пробел): ";
                std::cin >> item >> price;
                prices[item] = price;
                break;
        }
    }

    return 0;
}
