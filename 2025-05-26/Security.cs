class Security : Employee {
    string favorite_donut_taste;
    string favorite_weekday;

    public Security(
            string fio,
            DateOnly birth,
            double salary,
            uint experience_years,
            string favorite_donut_taste,
            string favorite_weekday) : base(fio, birth, salary, experience_years) {
        this.favorite_donut_taste = favorite_donut_taste;
        this.favorite_weekday = favorite_weekday;
    }

    public override void PrintInfo() {
        base.PrintInfo();
        Console.Out.WriteLine(@$"
Любимый вкус пончика: {favorite_donut_taste}
Любимый день недели: {favorite_weekday}
                ".Trim());
    }
}
