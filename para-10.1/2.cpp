#include <iostream>
#include <map>
#include <string>

#define PRICE_PER_MINUTE 0.6

unsigned parse_time(std::string& time) {
    return std::stoi(time.substr(0, time.find(':'))) * 60
            + std::stoi(time.substr(time.find(':') + 1, time.length()));
}

int main (int argc, char *argv[]) {
    std::map<std::string, unsigned> tickets;

    while (true) {
        std::string plate, time;

        std::cin >> plate >> time;

        unsigned time_minutes = parse_time(time);

        if (tickets.count(plate)) {
            std::cout << (time_minutes - tickets[plate]) * PRICE_PER_MINUTE << std::endl;
            tickets.erase(plate);
            continue;
        }

        tickets[plate] = time_minutes;
    }

    return 0;
}
