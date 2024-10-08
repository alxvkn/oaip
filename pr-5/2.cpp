#include <iostream>

int main(int argc, char *argv[]) {
    using namespace std;

    unsigned n, m;

    cout << "Введите n и m (через пробел): ";
    cin >> n >> m;

    char a[n][m];
    char characters_lookup[2] = { '.', '*' };
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < m; j++) {
            a[i][j] = characters_lookup[(j % 2) != (i % 2)];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
