module;

export module m;

namespace m {
const unsigned ENDS_WITH = 7;
const unsigned STARTS_WITH = 9;

export bool is_even(int n) {
    return n % 2 == 0;
}

export unsigned long long factorial(unsigned n) {
    return n == 1 ? 1 : n * factorial(n - 1);
}

int ends_with(int n) {
    return n % 10;
}

int power(int n, unsigned power) {
    int ret = 1;

    for (unsigned i = 0; i < power; i++) {
        ret *= n;
    }

    return ret;
}

int starts_with(int n) {
    int ret;

    int d = 10;

    unsigned i;
    for (i = 0; n / d != 0; i++) {
        d *= 10;
    }

    ret = n / power(10, i);

    return ret;
}

export bool starts_with_secret_digit(int n) {
    return starts_with(n) == STARTS_WITH;
}

export bool ends_with_secret_digit(int n) {
    return ends_with(n) == ENDS_WITH;
}

}
