#include <iostream>
#include <math.h>

double z(double x, double y) {
    return sin(pow(cos(x*y), 4));
}

int main (int argc, char *argv[]) {
    double x, y;

    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;

    std::cout << "z = " << z(x, y) << std::endl;

    return 0;
}
