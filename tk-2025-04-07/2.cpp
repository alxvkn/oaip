#include <array>
#include <iostream>
#include <random>

int random_int(int start, int end) {
    static std::random_device rd;
    static std::default_random_engine engine(rd());
    std::uniform_int_distribution<int> distribution(start, end);

    return distribution(engine);
}

int main (int argc, char *argv[]) {
    // Генератор случайных математических задач. Напишите программу,  
    // которая генерирует случайные математические задачи  
    // (например, сложение, вычитание, умножение) и  
    // проверяет правильность ответа пользователя. 

    const std::array<char, 3> operations({'+', '-', '*'});

    char operation = operations[random_int(0, operations.size() - 1)];

    int a = random_int(0, 10), b = random_int(0, 10);

    std::cout << a << " " << operation << " " << b << " = ";

    int guess;
    std::cin >> guess;

    bool correct;

    switch (operation) {
        case '+':
            correct = guess == a + b;
            break;
        case '-':
            correct = guess == a - b;
            break;
        case '*':
            correct = guess == a * b;
            break;
    }

    std::cout << (correct ? "Правильно!" : "Не очень правильно!") << std::endl;

    return 0;
}
