#include <iostream>
#include <ostream>
#include <stack>
#include <random>

int main (int argc, char *argv[]) {
    std::stack<int> st;

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<> distribution(10, 100);

    for (unsigned i = 0; i < 10; i++) {
        st.push(distribution(generator));
    }

    unsigned count = 0;
    std::cout << "stack:";
    while (st.size()) {
        std::cout << " " << st.top();
        if (st.top() % 7 == 2) {
            count++;
        }
        st.pop();
    }
    std::cout << std::endl;

    std::cout << "count: " << count << std::endl;

    return 0;
}
