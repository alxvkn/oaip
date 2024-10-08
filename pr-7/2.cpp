#include <iostream>
#include <set>

int main (int argc, char *argv[]) {
    std::set<int> s;

    while (true) {
        int a;
        std::cin >> a;
        std::cout << (s.count(a) ? "YES" : "NO") << std::endl;
        s.insert(a);
    }

    return 0;
}
