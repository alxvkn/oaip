#include <iostream>
#include <sstream>
#include <string>
#include <utility>

struct Car {
    std::string brand_and_model;
    int year;
    unsigned mileage;
    unsigned cost;

    enum Body {
        Sedan = 0,
        Coupe,
        Hatchback,
        SUV,

        begin = Sedan,
        end = SUV,
    } body;

    static std::string body_to_string(enum Body body) {
        switch (body) {
            case Sedan:
                return "Седан";
                break;
            case Coupe:
                return "Купе";
                break;
            case Hatchback:
                return "Хэтчбек";
                break;
            case SUV:
                return "Внедорожник";
                break;
        }
    }

    Car* next;
};

class CarShop {
    Car* head;

public:
    CarShop() : head(nullptr) {}

    ~CarShop() {
        Car* current = head;
        while (current != nullptr) {
            Car* to_delete = current;
            current = current->next;
            delete to_delete;
        }
    }

    void add_car(
        const std::string& brand_and_model,
        int year,
        unsigned mileage,
        unsigned cost,
        enum Car::Body body
    ) {
        Car* new_car = new Car {
            brand_and_model,
            year,
            mileage,
            cost,
            body,
        };

        if (!head) {
            head = new_car;
        } else {
            Car* temp = head;

            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = new_car;
        }
    }

    void print() {
        Car* c = head;
        while (c) {
            _print_car(*c);
            c = c->next;
        }
    }

    void print_by_mileage(const int mileage) {
        Car* c = head;
        while (c) {
            if (c->mileage == mileage)
                _print_car(*c);
            c = c->next;
        }
    }

    void print_by_cost(const unsigned cost) {
        Car* c = head;
        while (c) {
            if (c->cost == cost)
                _print_car(*c);
            c = c->next;
        }
    }

    void delete_by_brand_and_model(const std::string& brand_and_model) {
        Car* b = head;
        unsigned i = 0;

        while (b) {
            if (b->brand_and_model == brand_and_model) break;
            i++;
            b = b->next;
        }

        _delete_by_index(i);
    }

    void sort_by_year() {
        if (!head || !head->next) return;

        bool swapped;
        do {
            swapped = false;
            Car* c = head;
            while (c && c->next) {
                if (c->year > c->next->year) {
                    std::swap(c->brand_and_model, c->next->brand_and_model);
                    std::swap(c->year, c->next->year);
                    std::swap(c->mileage, c->next->mileage);
                    std::swap(c->cost, c->next->cost);
                    std::swap(c->body, c->next->body);
                    swapped = true;
                }
                c = c->next;
            }
        } while (swapped);
    }

    void sort_by_cost() {
        if (!head || !head->next) return;

        bool swapped;
        do {
            swapped = false;
            Car* c = head;
            while (c && c->next) {
                if (c->cost > c->next->cost) {
                    std::swap(c->brand_and_model, c->next->brand_and_model);
                    std::swap(c->year, c->next->year);
                    std::swap(c->mileage, c->next->mileage);
                    std::swap(c->cost, c->next->cost);
                    std::swap(c->body, c->next->body);
                    swapped = true;
                }
                c = c->next;
            }
        } while (swapped);
    }


private:
    void _print_car(const Car& car) {
        std::cout << "\"" << car.brand_and_model << "\""
            << ", " << car.year <<
            ", " << car.mileage <<
            ", " << car.cost <<
            ", " << Car::body_to_string(car.body) << std::endl;
    }

    void _delete_by_index(unsigned index) {
        if (!head) {
            std::cout << "empty list" << std::endl;
            return;
        }

        Car* b = head;

        if (index == 0) {
            head = head->next;
            delete b;
            return;
        }

        for (unsigned i = 0; b && i < index - 1; i++) {
            b = b->next;
        }

        if (!b->next) {
            std::cout << "out of bounds" << std::endl;
            return;
        }

        Car* next = b->next->next ? b->next->next : nullptr;
        delete b->next;
        b->next = next;
    }
};

class CarShopUserInterface {
public:
    CarShopUserInterface(CarShop& car_shop) : _car_shop(car_shop) {};

    void ui_loop() {
        int input = -1;

        while (input) {
            std::cout << _prompt();
            std::cin >> input;
            switch (input) {
                case 1:
                    _add_car();
                    break;
                case 2:
                    _delete_by_brand_and_model();
                    break;
                case 3:
                    _find_by_mileage();
                    break;
                case 4:
                    _find_by_cost();
                    break;
                case 5:
                    _car_shop.sort_by_cost();
                    break;
                case 6:
                    _car_shop.sort_by_year();
                    break;
                case 7:
                    _car_shop.print();
                    break;
            }
        }
    }

private:
    CarShop& _car_shop;

    std::string _prompt() {
        std::stringstream ss;

        ss
            << '\n'
            << "1. Добавить машину\n"
            << "2. Удалить по марке и модели\n"
            << "3. Поиск по пробегу\n"
            << "4. Поиск по цене\n"
            << "5. Сортировка по цене\n"
            << "6. Сортировка по году выпуска\n"
            << "7. Вывести все машины\n"
            << "0. Выйти\n"
            << "> ";

        return ss.str();
    }

    void _add_car() {
        std::string brand_and_model;
        int year;
        unsigned cost, mileage;

        enum Car::Body body;

        std::cout << "Марка и модель: ";
        std::cin >> brand_and_model;

        std::cout << "Год выпуска: ";
        std::cin >> year;

        std::cout << "Цена: ";
        std::cin >> cost;

        std::cout << "Пробег: ";
        std::cin >> mileage;

        for (unsigned i = Car::Body::begin; i <= Car::Body::end; i++) {
            std::cout << i + 1 << ". "
                << Car::body_to_string((enum Car::Body)i) << "\n";
        }
        std::cout << "Кузов (из предложенных вариантов): ";
        std::cin >> (int&)body;
        (int&)body -= 1;

        _car_shop.add_car(brand_and_model, year, mileage, cost, body);
    }

    void _delete_by_brand_and_model() {
        std::string brand_and_model;

        std::cout << "Марка и модель: ";
        std::cin >> brand_and_model;

        _car_shop.delete_by_brand_and_model(brand_and_model);
    }

    void _find_by_mileage() {
        unsigned mileage;

        std::cout << "Пробег: ";
        std::cin >> mileage;

        _car_shop.print_by_mileage(mileage);
    }

    void _find_by_cost() {
        unsigned cost;

        std::cout << "Цена: ";
        std::cin >> cost;

        _car_shop.print_by_cost(cost);
    }
};

int main() {
    CarShop cs;

    cs.add_car("Toyota Camry", 2020, 15000, 2000000, Car::Sedan);
    cs.add_car("BMW X5", 2021, 10000, 5000000, Car::SUV);
    cs.add_car("Honda Civic", 2019, 30000, 1500000, Car::Sedan);
    cs.add_car("Mercedes-Benz E-Class", 2022, 5000, 4500000, Car::Sedan);
    cs.add_car("Ford Mustang", 2020, 20000, 3500000, Car::Coupe);
    cs.add_car("Audi Q7", 2021, 12000, 4000000, Car::SUV);
    cs.add_car("Nissan X-Trail", 2020, 25000, 1600000, Car::SUV);
    cs.add_car("Chevrolet Cruze", 2018, 60000, 900000, Car::Hatchback);
    cs.add_car("Kia Sportage", 2022, 3000, 1800000, Car::SUV);
    cs.add_car("Skoda Octavia", 2019, 40000, 1200000, Car::Sedan);

    CarShopUserInterface csui(cs);
    csui.ui_loop();

    return 0;
}
