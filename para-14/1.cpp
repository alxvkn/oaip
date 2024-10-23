#include <iostream>

using namespace std;

class Employee {
public:
    string last_name;
    double years_experience;
    double hourly_wage;
    double hours_worked;

    void from_keyboard() {
        cout << "Фамилия: ";
        cin >> last_name;
        cout << "Стаж: ";
        cin >> years_experience;
        cout << "Часовая зарплата: ";
        cin >> hourly_wage;
        cout << "Кол-во отработанных часов: ";
        cin >> hours_worked;
    }

    double payment() {
        return hourly_wage * hours_worked;
    }

    double bonus() {
        if (years_experience < 1) return 0;
        double monthly_salary = hourly_wage * 9 * 22;
        if (years_experience < 3) return (monthly_salary / 100) * 5;
        if (years_experience < 5) return (monthly_salary / 100) * 8;
        else return (monthly_salary / 100) * 15;
    }

    friend std::ostream& operator<<(std::ostream& out, const Employee& employee) {
        out << "Фамилия: " << employee.last_name << "\n"
            << "Стаж: " << employee.years_experience << "\n"
            << "Часовая зарплата: " << employee.hourly_wage << "\n"
            << "Кол-во отработанных часов: " << employee.hours_worked << endl;

        return out;
    }
};

int main() {
    Employee e;
    e.from_keyboard();
    cout << "Зарплата за отработанное время: " << e.payment() << endl;
    cout << "Премия (от месяца): " << e.bonus() << endl;
}
