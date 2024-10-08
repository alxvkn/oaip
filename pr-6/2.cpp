#include <algorithm>
#include <iostream>

int main (int argc, char *argv[]) {
    using namespace std;
    string s;
    getline(cin, s);

    unsigned index = s.find("А.С.");

    while (index != -1) {
        s.erase(index, 4);
        s.insert(index, "Алексаднр Сергеевич");
        index = s.find("А.С.", index + 1);
    }

    char choice;

    cout << "Вы хотите развернуть строку? [y/n] ";
    cin >> choice;

    if (choice == 'y')
        std::reverse(s.begin(), s.end());

    cout << s << std::endl;

    return 0;
}
