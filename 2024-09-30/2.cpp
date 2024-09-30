#include <iostream>
#include <set>

int main (int argc, char *argv[]) {
    std::set<int> s;
    unsigned n;
    std::cout << "N: ";
    std::cin >> n;

    for (unsigned i = 0; i < n; i++) {
        char c;
        int a;
        std::cin >> c;
        std::cin >> a;

        if (c == '+')
            s.insert(a);
        else if (c == '-') {
            s.erase(a);
        }
    }

    if (s.size() == 0) {
        std::cout << -1 << std::endl;
        return -1;
    }

    for (auto e : s) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}
