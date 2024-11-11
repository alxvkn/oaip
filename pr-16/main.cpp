#include <exception>
#include <iostream>
#include <string>
#include "GoofyFiles.hpp"

int main (int argc, char *argv[]) {
    const char* ERROR = "Что-то пошло не так.";
    GoofyFiles gf;

    int choice = -1;

    while (true) {
        std::cout << "\nВыберите действие:\n"
            "1. Создать файл\n"
            "2. Удалить файл\n"
            "3. Прочесть файл\n"
            "4. Перезаписать файл\n"
            "5. Дописать файл\n"
            "6. Посмотреть созданные файлы\n"
            "0. Выйти\n" << std::endl;

        std::cin >> choice;

        if (!choice) {
            break;
        }

        std::string path, content;

        if (choice == 6) {
            for (auto path : gf.created_files) {
                std::cout << path << std::endl;
            }
            continue;
        }

        std::cout << "Введите имя файла: ";
        std::cin >> path;

        switch (choice) {
            case 1:
                std::cout << "Введите содержмиое файла: ";
                std::cin >> content;
                if (gf.create_file(path, content)) {
                    std::cout << "Файл успешно создан" << std::endl;
                } else std::cout << ERROR << std::endl;
                break;
            case 2:
                if (gf.delete_file(path)) {
                    std::cout << "Файл успешно удалён" << std::endl;
                } else std::cout << ERROR << std::endl;
                break;
            case 3:
                try {
                    content = gf.read_file(path);
                } catch (std::exception e) {
                    std::cout << ERROR << std::endl;
                }
                std::cout << "Содержимое файла: " << content << std::endl;
                break;
            case 4:
                std::cout << "Введите содержимое файла: ";
                std::cin >> content;
                if (gf.rewrite_file(path, content)) {
                    std::cout << "Файл успешно перезаписан" << std::endl;
                } else std::cout << ERROR << std::endl;
                break;
            case 5:
                std::cout << "Введите содержимое для дописания: ";
                std::cin >> content;
                if (gf.append_file(path, content)) {
                    std::cout << "Файл успешно дописан" << std::endl;
                } else std::cout << ERROR << std::endl;
                break;
        }
    }

    return 0;
}
