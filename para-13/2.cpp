#include <iostream>
#include <string>

using namespace std;

template <class I>
bool check_palindrome(I start, I end) {
    if (start >= end)
        return true;
    if (*start != *end)
        return false;

    return check_palindrome(start+1, end-1);
}

bool is_palindrome(string s) {
    size_t len = s.length();

    return check_palindrome(s.begin(), s.end() - 1);
}

int main(int argc, char *argv[]) {
    string s;
    cin >> s;

    cout << (is_palindrome(s) ? "YES" : "NO") << endl;

    return 0;
}
