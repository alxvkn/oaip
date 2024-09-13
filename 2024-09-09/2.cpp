#include <iostream>
#include <string>

struct Greeting {
    std::string author_name;
    std::string greeting;
    std::string question_name;
    std::string question_code;
} greeting = {
    .author_name = "Даня Графов и Алексей Затравкин",
    .greeting = "Привет! Это",
    .question_name = "Как Вас зовут?",
    .question_code = "Сколько лет Вы занимаетесь программированием?",
};

struct User {
    std::string name;
    int code;
};

int main (int argc, char *argv[]) {
    struct User user;
    std::cout << greeting.greeting << " "
        << greeting.author_name << std::endl
        << greeting.question_name << std::endl;

    std::cin >> user.name;
    std::cout << greeting.question_code << std::endl;
    std::cin >> user.code;

    std::cout << "Вас зовут " << user.name
        << ". Вы занимаетесь программированием "
        << user.code << " лет" << std::endl;

    return 0;
}
