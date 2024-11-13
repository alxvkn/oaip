#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int main (int argc, char *argv[]) {
    std::stack<int> st;

    for (unsigned i = 0; i < 10; i++) {
        double a;
        std::cin >> a;
        st.push(a);
    }

    std::vector<int> v;

    while (st.size()) {
        v.push_back(st.top());
        st.pop();
    }

    std::reverse(v.begin(), v.end());

    std::stack<int> _st;

    for (auto e : v) {
        _st.push(e >= 0 ? 1 : -1);
    }

    while (_st.size()) {
        std::cout << " " << _st.top();
        _st.pop();
    }
    std::cout << std::endl;

    return 0;
}
