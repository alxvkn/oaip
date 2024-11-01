#include <iostream>
#include <vector>

using namespace std;

bool funcOfarr(vector<int> a) {
    for (size_t i = 1; i < a.size(); i++) {
        if (a[i] <= a[i - 1]) {
            return false;
        }
    }
    return true;
}

int main (int argc, char *argv[]) {
    int n;

    cin >> n;
    vector<int> a(n);

    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << (funcOfarr(a) ? "Yes" : "No") << endl;

    return 0;
}
