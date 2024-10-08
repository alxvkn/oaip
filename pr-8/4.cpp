#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define FILENAME "phone.txt"

void add_entry_dialog() {
    fstream out(FILENAME, ios::app);
    if (!out.is_open()) throw new exception();

    string first, last, number;

    cout << "Фамилия -> ";
    cin >> last;
    cout << "Имя -> ";
    cin >> first;
    cout << "Телефон -> ";
    cin >> number;

    out << last << " " << first << " " << number << endl;
    out.close();
    cout << "Информация добавлена." << endl;
}

void search_dialog() {
    ifstream in(FILENAME);

    string search_last;

    cout << "Фамилия, по которой искать -> ";
    cin >> search_last;

    string first, last, number;
    string line;

    unsigned count = 0;
    while (getline(in, line)) {
        stringstream line_stream(line);

        line_stream >> last >> first >> number;

        if (last == search_last) {
            count++;
            cout << line << "\n";
        }
    }

    if (!count) {
        cout << "В справочнике данных о " << search_last << " нет." << endl;
    }
}

void print_entries() {
    ifstream in(FILENAME);
    string s;

    while (getline(in, s)) {
        cout << s << "\n";
    }

    cout << endl;
}

int main(int argc, char *argv[]) {
    int choice = -1;

    while (choice) {
        cout << "*** Телефонный справочник ***\n"
            << "1. Добавление\n"
            << "2. Поиск\n"
            << "3. Вывод всего списка\n"
            << "0. Выход" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                add_entry_dialog();
                break;
            case 2:
                search_dialog();
                break;
            case 3:
                print_entries();
                break;
        }
    }

    return 0;
}
