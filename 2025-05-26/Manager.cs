class Manager : Employee {
    uint employees_count;
    string department_name;

    public Manager(
            string fio,
            DateOnly birth,
            double salary,
            uint experience_years,
            uint employees_count,
            string department_name) : base(fio, birth, salary, experience_years) {
        this.employees_count = employees_count;
        this.department_name = department_name;
    }

    public override void PrintInfo() {
        base.PrintInfo();
        Console.Out.WriteLine(@$"
Количество подчинённых: {employees_count}
Название отдела: {department_name}
                ".Trim());
    }
}
