#include <iostream>
#include <utility>

template <class T>
void selection_sort(T* arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        size_t min_index = i; // индекс минимального элемента
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            // T temp = arr[i];
            // arr[i] = arr[min_index];
            // arr[min_index] = temp;
            std::swap(arr[i], arr[min_index]);
        }
    }
}

int main (int argc, char *argv[]) {
    size_t x_length;
    std::cout << "n: ";
    std::cin >> x_length;

    int* x = new int[x_length];

    std::cout << "x: ";
    for (unsigned i = 0; i < x_length; i++) {
        std::cin >> x[i];
    }

    int* y = new int[x_length];

    // x_offset используется для того, чтобы переходить к следующему
    // элементу в исходном массиве **x**, не увеличивая индекс для
    // массива-получателя **y**, в том случае, если встретится элемент
    // меньше, либо равен 3
    //
    // а мог бы быть просто меньше 3 (<3) :3
    //
    // (реализуется сжатие)
    unsigned y_actual_length = 0;
    for (unsigned i = 0, x_offset = 0; i + x_offset < x_length;) {
        int element = x[i + x_offset];
        if (element > 3) {
            y[i] = element;
            i++;
            y_actual_length++;
        } else {
            x_offset++;
        }
    }

    std::cout << "x: ";
    for (unsigned i = 0; i < x_length; i++) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "y: ";
    for (unsigned i = 0; i < y_actual_length; i++) {
        std::cout << y[i] << " ";
    }
    std::cout << std::endl;

    int* y_sorted = new int[y_actual_length];

    for (unsigned i = 0; i < y_actual_length; i++)
        y_sorted[i] = y[i];

    selection_sort(y_sorted, y_actual_length);

    std::cout << "y после сортировки: ";
    for (unsigned i = 0; i < y_actual_length; i++) {
        std::cout << y_sorted[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
