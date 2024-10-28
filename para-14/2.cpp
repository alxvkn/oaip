#include <iostream>

using namespace std;

unsigned factorial(unsigned n) {
    return n == 1 ? 1 : n * factorial(n - 1);
}

unsigned combinations(unsigned n, unsigned k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main (int argc, char *argv[]) {
    unsigned n, k;

    cout << "n: ";
    cin >> n;
    cout << "k: ";
    cin >> k;

    cout << combinations(n, k) << endl;

    return 0;
}
