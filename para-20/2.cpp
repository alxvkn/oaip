#include <stdexcept>

template <class T>
class BankAccount {
private:
    T _balance;
public:
    BankAccount(T balance = 0) : _balance(balance) {}

    void deposit(T sum) {
        _balance += sum;
    }

    void withdraw(T sum) {
        if (sum > _balance) {
            throw std::runtime_error("Withdrawal sum is larger than balance.");
        }
        _balance -= sum;
    }

    T get_balance() {
        return _balance;
    }
};
