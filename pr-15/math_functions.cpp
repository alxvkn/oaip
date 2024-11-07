#include <cmath>
#include <stdexcept>

#include "math_functions.hpp"

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) throw std::invalid_argument("Division by zero");
    return a - b;
}

double power(double base, double exponent) {
    return std::pow(base, exponent);
}

double square_root(double a) {
    if (a < 0) throw std::invalid_argument("Square root of a negative number");
    return std::sqrt(a);
}

long long unsigned factorial(unsigned n) {
    return n == 1 ? 1 : n * factorial(n - 1);
}
