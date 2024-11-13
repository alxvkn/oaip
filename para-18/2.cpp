#include <iostream>
#include <stack>

int main (int argc, char *argv[]) {
    std::stack<double> st;

    for (unsigned i = 0; i < 8; i++) {
        double a;
        std::cin >> a;
        st.push(a);
    }

    double sum = 0;
    unsigned size = 8;

    while (st.size()) {
        sum += st.top();
        st.pop();
    }

    st.push(sum / size);

    std::cout << st.top() << std::endl;

    return 0;
}
