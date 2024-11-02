module;
#include <exception>
export module calculator;

namespace calculator {

export template <typename T>
T add(T a, T b) {
    return a + b;
}

export template <typename T>
T sub(T a, T b) {
    return a - b;
}

export template <typename T>
T mul(T a, T b) {
    return a * b;
}

export template <typename T>
T div(T a, T b ) {
    if (b == 0) throw std::exception();
    return a / b;
}

export int pow(int a, unsigned power) {
    int                         ret = 1;

    for (unsigned i = 0; i < power; i++) {
        ret *= a;
    }

    return ret;
}
}
