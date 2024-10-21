#include <iostream>

using namespace std;

unsigned factorial(unsigned n) {
    return (n == 1 ? n : n * factorial(n - 1));
}

int main() {
    unsigned n;
    cin >> n;
    cout << factorial(n) << endl;
}
