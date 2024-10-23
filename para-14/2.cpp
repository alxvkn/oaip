#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    int hours, minutes, seconds;

    cin >> hours >> minutes >> seconds;

    int in_seconds = (hours * 60*60) + (minutes * 60) + seconds;

    int s;
    cin >> s;

    in_seconds -= s;

    hours = in_seconds / (60*60);
    minutes = (in_seconds / 60) % 60;
    seconds = in_seconds % 60;

    cout << hours << ":" << minutes << ":" << seconds << endl;

    cout << "a: ";
    cin >> hours >> minutes >> seconds;
    int in_seconds_a = (hours * 60*60) + (minutes * 60) + seconds;

    cout << "b: ";
    cin >> hours >> minutes >> seconds;
    int in_seconds_b = (hours * 60*60) + (minutes * 60) + seconds;

    cout << "a - b: " << in_seconds_a - in_seconds_b << endl;

    return 0;
}
