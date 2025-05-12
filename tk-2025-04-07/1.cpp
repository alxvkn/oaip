#include <iostream>
#include <set>
#include <string>

using namespace std;

bool is_anagram_of(string& a, string& b) {
    multiset<char> _a, _b;

    for (char character : a) {
        _a.insert(character);
    }

    for (char character : b) {
        _b.insert(character);
    }

    return _a == _b;
}

int main (int argc, char *argv[]) {
    // Поиск анаграмм. Создайте приложение, которое принимает от пользователя  
    // две строки и проверяет, являются ли они анаграммами  
    // (состоят из одних и тех же символов в разном порядке). 

    string a, b;

    cout << "Введите строку a: ";
    cin >> a;

    cout << "Введите строку b: ";
    cin >> b;

    cout << "Строки - " << (is_anagram_of(a, b) ? "" : "не ") << "анаграммы.";

    return 0;
}
