class Developer : Employee {
    string uses_language;
    string hates_language;

    public Developer(
            string fio,
            DateOnly birth,
            double salary,
            uint experience_years,
            string uses_language,
            string hates_language) : base(fio, birth, salary, experience_years) {
        this.uses_language = uses_language;
        this.hates_language = hates_language;
    }

    public override void PrintInfo() {
        base.PrintInfo();
        Console.Out.WriteLine(@$"
Используемый ЯП: {uses_language}
Нелюбимый ЯП: {hates_language}
                ".Trim());
    }
}
