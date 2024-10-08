#include <iostream>

int main(void) {
    std::string code;
    double time, cost;

    std::cout << "Введите код города: ";
    std::cin >> code;

    if (code == "423")
        cost = 2.2;
    else if (code == "095")
        cost = 1;
    else if (code == "815")
        cost = 1.2;
    else if (code == "846")
        cost = 1.4;
    else {
        std::cout << "Введён неизвестный код города."
            << std::endl;
        return 1;
    }

    std::cout << "Введите длительность разговора: ";
    std::cin >> time;

    std::cout << "Стоимость разговора: "
        << cost * time << std::endl;;

    return 0;
}
