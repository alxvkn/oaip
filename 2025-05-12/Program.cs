namespace _2025_05_12;

class Program
{
    static void Main(string[] args)
    {
        ClockSystem clocksystem = new ClockSystem();
        clocksystem.Run();
    }
}

class ClockSystem {
    public ClockSystem() {
        random = new Random();
        temperature = random.Next(0, 10);
        UpdateTime();
    }

    Random random;
    DateTime datetime;
    int temperature;
    string status = "";

    public void UpdateTime() {
        datetime = DateTime.Now;
    }

    public void UpdateTemperature() {
        bool negative = random.Next(2) == 1;
        temperature += negative ? -1 : 1;
        if (temperature > 40) temperature = 40;
        else if (temperature < -40) temperature = -40;

        status =
            (temperature < 0) ? "Холодно" :
            (temperature <= 20) ? "Прохладно" :
            (temperature <= 30) ? "Тепло" :
            "Жарко";
    }

    public string GetTemperatureStatus() {
        return status;
    }

    public void Display() {
        Console.Clear();
        Console.WriteLine(
$@"Время: {datetime.TimeOfDay}
Температура: {temperature}
Оценка: {status}");
    }

    public void Run() {
        while (true) {
            Display();
            UpdateTime();
            UpdateTemperature();
            Thread.Sleep(1000);
        }
    }
}
