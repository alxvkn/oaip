namespace task_4;

class Program
{
    static DateTime askDate() {
        Console.Write("Введите день: ");
        int day = int.Parse(Console.ReadLine() ?? throw new Exception());
        Console.Write("Введите месяц (1-12): ");
        int month = int.Parse(Console.ReadLine() ?? throw new Exception());
        Console.Write("Введите год (гггг): ");
        int year = int.Parse(Console.ReadLine() ?? throw new Exception());
        return new DateTime(year, month, day);
    }
    static void Main(string[] args)
    {
        Console.WriteLine("Первая дата");
        var first = askDate();
        Console.WriteLine();

        Console.WriteLine("Вторая дата");
        var second = askDate();
        Console.WriteLine();
        
        Console.WriteLine($"Разница в днях: {(second - first).TotalDays}");
        Console.WriteLine($"Разница в часах: {(second - first).TotalHours}");
        Console.WriteLine($"Разница в минутах: {(second - first).TotalMinutes}");
    }
}
