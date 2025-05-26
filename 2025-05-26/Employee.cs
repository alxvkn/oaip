class Employee {
    string fio;
    DateOnly birth;
    double salary;
    uint experience_years;

    public Employee(string fio, DateOnly birth, double salary, uint experience_years) {
        this.fio = fio;
        this.birth = birth;
        this.salary = salary;
        this.experience_years = experience_years;
    }

    public virtual void PrintInfo() {
        Console.Out.WriteLine(@$"
ФИО: {fio}
Дата рождения: {birth}
Оклад: {salary}
Опыт работы: {experience_years} {get_years_suffix(experience_years)}
                ".Trim());
    }

    string get_years_suffix(uint years) {
        if (experience_years > 4 && experience_years < 21)
            return "лет";
        else if (experience_years % 10 == 1)
            return "год";
        else if (experience_years % 10 < 5)
            return "года";
        else
            return "лет";
    }
}
