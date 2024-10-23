#include <array>
#include <iostream>
#include <set>

using namespace std;

int main (int argc, char *argv[]) {
    int n;
    cin >> n;

    array<char, 4> digits;

    digits[0] = n % 10;
    digits[1] = n / 10 % 10;
    digits[2] = n / 100 % 10;
    digits[3] = n / 1000 % 100;

    multiset<char> uniq;
    bool has_two = false;

    for (auto d : digits) {
        uniq.insert(d);

        if (uniq.count(d) > 1) {
            has_two = true;
            break;
        }
    }

    cout << boolalpha << has_two << endl;

    return 0;
}
