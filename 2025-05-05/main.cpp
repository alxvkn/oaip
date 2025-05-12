#include <chrono>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include <thread>

class TemperatureRecord {
public:
    int temperature;
    std::chrono::time_point<std::chrono::system_clock> timestamp;

    std::string to_string() {
        std::stringstream ss;

        auto time = std::chrono::system_clock::to_time_t(timestamp);
        std::string time_string = std::ctime(&time);
        time_string.pop_back();
        ss << time_string << " " << temperature << "C";

        return std::move(ss.str());
    }
};

class TemperatureSensor {
public:
    TemperatureSensor(int start_temperature = 20, int temperature_variance = 5)
    : start_temperature(start_temperature), temperature_variance(temperature_variance) {
        std::srand(std::time(0));
    }

    int measure() {
        bool negative = std::rand() % 2 == 0;
        int temperature = last_temperature + (negative ? -temperature_variance : temperature_variance);
        last_temperature = temperature;
        return temperature;
    }
private:
    const int start_temperature;
    const int temperature_variance;
    int last_temperature = start_temperature;
};

class SensorManager {
public:
    SensorManager(std::unique_ptr<TemperatureSensor> sensor, size_t n_keep_records)
    : n_keep_records(n_keep_records), sensor(std::move(sensor)) {}

    SensorManager(SensorManager&& other)
    : n_keep_records(other.n_keep_records), sensor(std::move(other.sensor)) {}

    void update() {
        records.push_back({
            .temperature = sensor->measure(),
            .timestamp = std::chrono::system_clock::now(),
        });

        if (records.size() > n_keep_records) {
            records.erase(records.begin());
        }
    }

    std::vector<TemperatureRecord> records;
private:
    std::unique_ptr<TemperatureSensor> sensor;
    const size_t n_keep_records;
};

int main (int argc, char *argv[]) {
    using namespace std::chrono_literals;

    std::vector<SensorManager> sensor_manangers;

    for (int i = 0; i < 5; i++) {
        sensor_manangers.emplace_back(std::make_unique<TemperatureSensor>(20, 5), 4);
    }

    while (true) {
        for (int i = 0; i < sensor_manangers.size(); i++) {
            auto& manager = sensor_manangers[i];
            manager.update();

             std::cout << "sensor #" << i << ":" << std::endl;
            for (auto r : manager.records) {
                std::cout << r.to_string() << std::endl;
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;
        std::this_thread::sleep_for(2s);
    }

    return 0;
}
