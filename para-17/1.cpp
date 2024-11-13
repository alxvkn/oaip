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
    size_t b_length;
    std::cout << "n: ";
    std::cin >> b_length;

    int* b = new int[b_length];

    std::cout << "b: ";
    for (unsigned i = 0; i < b_length; i++) {
        std::cin >> b[i];
    }

    int* c = new int[b_length];

    // b_offset используется для того, чтобы переходить к следующему
    // элементу в исходном массиве **b**, не увеличивая индекс для
    // массива-получателя **c**, в том случае, если встретится нулевой элемент.
    //
    // (реализуется сжатие)
    unsigned c_actual_length = 0;
    for (unsigned i = 0, b_offset = 0; i + b_offset < b_length;) {
        int element = b[i + b_offset];
        if (element != 0) {
            c[i] = element * element;
            i++;
            c_actual_length++;
        } else {
            b_offset++;
        }
    }

    std::cout << "b: ";
    for (unsigned i = 0; i < b_length; i++) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "c: ";
    for (unsigned i = 0; i < c_actual_length; i++) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    int* c_sorted = new int[c_actual_length];

    for (unsigned i = 0; i < c_actual_length; i++)
        c_sorted[i] = c[i];

    selection_sort(c_sorted, c_actual_length);

    std::cout << "c после сортировки: ";
    for (unsigned i = 0; i < c_actual_length; i++) {
        std::cout << c_sorted[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
