namespace _2025_05_26;

class Program
{
    static void Main(string[] args)
    {
        List<Employee> employees = [
            new Manager(
                    "манагеров манагер манагерович",
                    new DateOnly(1999, 01, 01),
                    100000.01,
                    3,
                    10,
                    "финансовый"),
            new Manager(
                    "манагеровна манагера манагеровична",
                    new DateOnly(2000, 02, 03),
                    999999.99,
                    1,
                    5,
                    "финансовый"),
            new Developer(
                    "разработчев разработчик разработкович",
                    new DateOnly(2001, 09, 11),
                    130000.37,
                    3,
                    "Java",
                    "JavaScript"),
            new Developer(
                    "разработчева разработчица разработковична",
                    new DateOnly(1998, 05, 15),
                    132000.37,
                    3,
                    "C++",
                    "C"),
            new Security(
                    "охранников шах сесуританович",
                    new DateOnly(1986, 04, 13),
                    80000.00,
                    15,
                    "ванильный",
                    "среда"
                    )
                ];

        foreach (var e in employees) {
            e.PrintInfo();
            Console.WriteLine();
        }
    }
}
