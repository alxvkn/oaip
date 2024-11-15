#include <algorithm>
#include <iostream>
#include <chrono>
#include <random>
#include <array>
#include <utility>

template <class T>
void inverse_selection_sort(T* arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        size_t max_index = i; // индекс максимального элемента
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        if (max_index != i) {
            std::swap(arr[i], arr[max_index]);
        }
    }
}

template <class T>
void inverse_bubble_sort(T* arr, size_t size) {
    for (unsigned i = 0; i < size - 1; i++) {
        for (unsigned j = 0; j < size - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                std::swap(arr[j], arr[j + j]);
            }
        }
    }
}

int main (int argc, char *argv[]) {
    const size_t SIZE = 10;
    std::array<int, SIZE> arr;

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<> distribution(-50, 100);

    for (unsigned i = 0; i < SIZE; i++) {
        arr[i] = distribution(generator);
    }

    std::array<int, arr.size()> arr_selection;

    for (unsigned i = 0; i < SIZE; i++) {
        arr_selection[i] = arr[i];
    }

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    inverse_selection_sort(arr_selection.data(), arr_selection.size());
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "selection_sort: " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    std::array<int, arr.size()> arr_bubble;

    for (unsigned i = 0; i < SIZE; i++) {
        arr_bubble[i] = arr[i];
    }

    begin = std::chrono::steady_clock::now();
    inverse_bubble_sort(arr_bubble.data(), SIZE);
    end = std::chrono::steady_clock::now();

    std::cout << "bubble_sort: " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    std::array<int, arr.size()> arr_sort;

    for (unsigned i = 0; i < SIZE; i++) {
        arr_sort[i] = arr[i];
    }

    begin = std::chrono::steady_clock::now();
    std::sort(arr_sort.begin(), arr_sort.end());
    end = std::chrono::steady_clock::now();

    std::cout << "sort: " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    std::cout << "arr: ";
    for (auto e : arr) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "arr_selection: ";
    for (auto e : arr_selection) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "arr_bubble: ";
    for (auto e : arr_bubble) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "arr_sort: ";
    for (auto e : arr_sort) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}
