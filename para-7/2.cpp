#include <iostream>
#include <string>

int main(void) {
    int correct = 0, total = 5;

    std::string ans;

    std::cout << "Каков будет результат выражения a % 10, если a = 14?" << std::endl;
    std::cin >> ans;
    if (ans == "4") correct++;

    std::cout << "Как расширение какого языка был разработан C++?" << std::endl;
    std::cin >> ans;
    if (ans == "C" or ans == "c") correct++;

    std::cout << "Если i = 2, то чему будет равна i после выполнения оператора i++?" << std::endl;
    std::cin >> ans;
    if (ans == "3") correct++;

    std::cout << "Как называется библиотека для использования таких объектов ввода-вывода как std::cin и std::cout?" << std::endl;
    std::cin >> ans;
    if (ans == "iostream") correct++;

    std::cout << "Что выведет следующий код:" << std::endl
        << "int a = (5 == 5 ? 3 : 1);" << std::endl
        << "std::cout << a << std::endl;" << std::endl;
    std::cin >> ans;
    if (ans == "3") correct++;

    std::cout << correct << " правильных из " << total << " вопросов всего."
        << std::endl << "Ваш результат: " << correct * 100 / total << "%"
        << std::endl;

    return 0;
}
