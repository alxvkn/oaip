#include <iostream>

int main(int argc, char *argv[]) {
    using namespace std;

    unsigned n, m;

    cout << "Введите n и m (через пробел): ";
    cin >> n >> m;

    int A[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            A[i][j] = i * j;
        }
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout.width(3); // Свойство width устанавливает ширину элемента.
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
