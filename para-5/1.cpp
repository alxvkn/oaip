#include <cmath>
#include <iostream>

class CosBC {
public:
    CosBC(double a, double b) : _a(a), _b(b) {}
    double calculate() {
        _c = 2 * _a + _b;
        return cos(_b*_c);
    }
private:
    const double _a, _b;
    double _c;
};

int main (int argc, char *argv[]) {
    double a, b;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;

    auto cosbc = CosBC(a, b);
    std::cout << "result: " << cosbc.calculate() << std::endl;

    return 0;
}
