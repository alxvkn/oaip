#include <cmath>
#include <iostream>

using namespace std;

double length(double v[], size_t n) {
    double sum_of_squares = 0;

    for (unsigned i = 0; i < n; i++) {
        sum_of_squares += v[i] * v[i];
    }

    return sqrt(sum_of_squares);
}

int main (int argc, char *argv[]) {
    size_t n;
    cout << "сколько координат у вектора? ";
    cin >> n;

    double v[n];

    for (unsigned i = 0; i < n; i++) {
        cout << "значение по координате #" << i+1 << ": ";
        cin >> v[i];
    }

    cout << "длина этого вектора: " << length(v, n) << endl;

    return 0;
}
