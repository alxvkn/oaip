#include <vector>
#include <iostream>
#include <random>

template <class T>
class Dubstep {
    std::vector<T> v;

    unsigned _partition(unsigned l, unsigned r) {
        T x = v[r];
        unsigned less = l;
        for (unsigned i = l; i < r; ++i) {
            if (v[i] <= x) {
                std::swap(v[i], v[less]);
                ++less;
            }
        }
        std::swap(v[less], v[r]);
        return less;
    }

    void _quick_sort_impl(unsigned l, unsigned r) {
        if (l < r) {
            unsigned q = _partition(l, r);
            _quick_sort_impl(l, q - 1);
            _quick_sort_impl(q + 1, r);
        }
    }
public:
    void quick_sort() {
        if (!v.empty()) {
            _quick_sort_impl(0, v.size() - 1);
        }
    }

    Dubstep(size_t size) {
        std::random_device rand_dev;
        std::mt19937 generator(rand_dev());
        std::uniform_int_distribution<> distribution(-50, 100);

        for (unsigned i = 0; i < size; i++) {
            v.push_back(distribution(generator));
        }
    }
    Dubstep(std::vector<T> v) : v(std::move(v)) {}

    void print() {
        for (auto e : v) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

    void selection_sort() {
        for (int i = 0; i < v.size() - 1; i++) {
            size_t min_index = i; // индекс максимального элемента
            for (int j = i + 1; j < v.size(); j++) {
                if (v[j] < v[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                std::swap(v[i], v[min_index]);
            }
        }
    }

    void bubble_sort() {
        for (unsigned i = 0; i < v.size() - 1; i++) {
            for (unsigned j = 0; j < v.size() - 1 - i; j++) {
                if (v[j] > v[j + 1]) {
                    std::swap(v[j], v[j + 1]);
                }
            }
        }
    }

    ~Dubstep() {
        std::cout << "destructor: ";
        print();
    }
};

int main() {
    auto a = Dubstep<int>(10);
    auto b = Dubstep<int>({ 4, 3, 2, 1, 8, -14 });
    auto c = Dubstep<int>(20);

    a.print();
    a.selection_sort();
    a.print();

    b.print();
    b.bubble_sort();
    b.print();

    c.print();
    c.quick_sort();
    c.print();
}
