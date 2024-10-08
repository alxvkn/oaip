#include <cctype>
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
    std::string s;

    std::getline(std::cin, s);

    for (unsigned i = 1; i < s.length(); i++) {
        if (s[i - 1] == ' ') {
            s[i] = std::toupper(s[i]);
        }
    }

    std::cout << s << std::endl;

    return 0;
}
