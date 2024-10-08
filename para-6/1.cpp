#include <iostream>
#include <cmath>

template <typename T>
class Calculator {
public:
    T add(T a, T b) {
        return a + b;
    }
    T sub(T a, T b) {
        return a - b;
    }
    T div(T a, T b) {
        return a / b;
    }
    T mul(T a, T b) {
        return a * b;
    }

    T cube_area(T a) {
        return 6 * a * a;
    }

    T triangle_area(T a, T b, T c) {
        T p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    T trapezium_area(T a, T b, T h) {
        return ((a + b) / 2) * h;
    }

    T parallelepiped_volume(T base_area, T h) {
        return base_area * h;
    }
};

int main (int argc, char *argv[]) {
    auto calc = Calculator<double>();

    double a, b, c;
    
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;

    std::cout << "a + b = " << calc.add(a, b) << std::endl;
    std::cout << "a - b = " << calc.sub(a, b) << std::endl;
    std::cout << "a / b = " << calc.div(a, b) << std::endl;
    std::cout << "a * b = " << calc.mul(a, b) << std::endl;
    
    std::cout << "сторона куба: ";
    std::cin >> a;
    std::cout << "площадь поверхности куба = " << calc.cube_area(a) << std::endl;

    std::cout << "стороны треугольника:\n" << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "c: ";
    std::cin >> c;

    std::cout << "площадь треугольника = " << calc.triangle_area(a, b, c) << std::endl;

    std::cout << "основания трапеции:\n" << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;

    std::cout << "высота трапеции: ";
    std::cin >> c;
    std::cout << "площадь трапеции: " << calc.trapezium_area(a, b, c) << std::endl;

    std::cout << "площадь основания параллелепипеда: ";
    std::cin >> a;
    std::cout << "высота параллелепипеда: ";
    std::cin >> b;

    std::cout << "объём параллелепипеда = " << calc.parallelepiped_volume(a, b) << std::endl;

    return 0;
}
