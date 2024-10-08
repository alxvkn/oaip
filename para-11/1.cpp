#include <iostream>
#include <fstream>

#define FILENAME "1.txt"

int main (int argc, char *argv[]) {
    using namespace std;
    string s;
    char choice;

    ofstream out;

    cout << "Вы хотите перезаписать файл? [y/n] ";
    cin >> choice;

    if (choice == 'y') {
        out = ofstream(FILENAME);
    } else {
        out = ofstream(FILENAME, ios::app);
    }

    if (!out.is_open())
        return -1;

    cout << "Введите строку: ";
    getline(cin, s);
    getline(cin, s);

    out << s << endl;

    out.close();

    cout << "Вы хотите вывести файл? [y/n] ";
    cin >> choice;

    if (choice == 'y') {
        ifstream in(FILENAME);
        string s;

        while (getline(in, s)) {
            cout << s << "\n";
        }

        cout << endl;
    }

    return 0;
}
