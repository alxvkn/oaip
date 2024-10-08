#include <iostream>
#include <fstream>
#include <random>

using namespace std;

void fill_file(const string& filename) {
    ofstream out(filename);

    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_int_distribution<> distribution(0, 100);

    for (unsigned i = 0; i < 100; i++) {
        out << distribution(generator) << "\n";
    }

    out.close();
}

void print_file(const string& filename) {
    ifstream in(filename);

    string s;
    unsigned i = 0;

    while (getline(in, s)) {
        cout << s << " ";
        if (++i % 10 == 0) cout << "\n";
    }

    cout << endl;
}

int main (int argc, char *argv[]) {
    string filename;
    cout << "Введите имя файла: ";
    cin >> filename;

    fill_file(filename);

    int choice = -1;

    while (choice != 0) {
        cout << "Вы хотите:\n1) Вывести значения\n2) Сгенерировать новые\n0) Выйти" << endl;
        cin >> choice;

        if (choice == 1) {
            print_file(filename);
        } else if (choice == 2) {
            fill_file(filename);
        }
    }

    return 0;
}
