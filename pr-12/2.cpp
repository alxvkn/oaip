#include <iostream>

using namespace std;

int power(int n, unsigned power) {
    int ret = 1;

    for (unsigned i = 0; i < power; i++) {
        ret *= n;
    }

    return ret;
}

int first_digits(int n, int k) {
    int ret;

    int d = 1;

    unsigned i;
    for (i = 0; n / d != 0; i++) {
        d *= 10;
    }

    ret = n / power(10, i - k);

    return ret;
}

int main (int argc, char *argv[]) {
    int n, k;
    cin >> n >> k;
    cout << first_digits(n, k) << endl;

    return 0;
}
