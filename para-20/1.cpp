#include <iostream>

template <class T>
class Rectangle {
public:
    T width;
    T height;

    Rectangle(T width, T height) : width(width), height(height) {}

    T area() {
        return width * height;
    }

    T perimeter() {
        return (width + height) * 2;
    }
};

int main() {
    Rectangle<int> a(3, 2);
    Rectangle<int> b(5, 4);
    Rectangle<int> c(8, 1);

    std::cout << "a:\n"
        << "width: " << a.width << "\n"
        << "height: " << a.height << "\n"
        << "area(): " << a.area() << "\n"
        << "perimeter(): " << a.perimeter() << "\n"
        << std::endl;

    std::cout << "b:\n"
        << "width: " << b.width << "\n"
        << "height: " << b.height << "\n"
        << "area(): " << b.area() << "\n"
        << "perimeter(): " << b.perimeter() << "\n"
        << std::endl;

    std::cout << "c:\n"
        << "width: " << c.width << "\n"
        << "height: " << c.height << "\n"
        << "area(): " << c.area() << "\n"
        << "perimeter(): " << c.perimeter() << "\n"
        << std::endl;

}
