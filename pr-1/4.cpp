#include <iostream>
#include <cmath>

class Point2d {
public:
    double x;
    double y;

    double distance_to(Point2d p) {
        double dx = p.x - this->x;
        double dy = p.y - this->y;

        return sqrt((dx * dx) + (dy * dy));
    }
};

int main (int argc, char *argv[]) {
    Point2d a, b, c;

    std::cout << "Введите координаты углов (числа разделяйте пробелом):" << std::endl;
    std::cout << "x1 y1 -> ";
    std::cin >> a.x >> a.y;

    std::cout << "x2 y2 -> ";
    std::cin >> b.x >> b.y;

    std::cout << "x3 y3 -> ";
    std::cin >> c.x >> c.y;

    double a_ = a.distance_to(b);
    double b_ = b.distance_to(c);
    double c_ = c.distance_to(a);

    double p = (a_ + b_ + c_) / 2;
    double s = sqrt(p * (p - a_) * (p - b_) * (p - c_));

    std::cout << s << std::endl;

    return 0;
}
