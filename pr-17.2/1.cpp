#include <string>
#include <iostream>

#include <iostream>
#include <string>

// Структура для хранения информации о мышке
struct Mouse {
    std::string model;
    int dpi;
    std::string color;
    int price;
    std::string manufacturer;
    Mouse* next;  // указатель на следующий элемент в списке
};

// Класс для работы с однонаправленным связанным списком
class MouseList {
private:
    Mouse* head;  // указатель на первый элемент списка

public:
    // Конструктор, инициализируем список пустым
    MouseList() : head(nullptr) {}

    // Деструктор для освобождения памяти
    ~MouseList() {
        Mouse* current = head;
        while (current != nullptr) {
            Mouse* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    // Функция для добавления новой мышки в конец списка
    void addMouse(const std::string& model, int dpi, const std::string& color, int price, const std::string& manufacturer) {
        Mouse* newMouse = new Mouse{ model, dpi, color, price, manufacturer, nullptr };
        if (!head) {
            head = newMouse;
        }
        else {
            Mouse* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newMouse;
        }
    }

    // Функция для удаления мышки по индексу
    void removeMouse(int index) {
        if (index < 0 || !head) {
            std::cout << "Invalid index or empty list!" << std::endl;
            return;
        }

        Mouse* temp = head;

        if (index == 0) {
            head = head->next;
            delete temp;
            return;
        }

        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            std::cout << "Index out of bounds!" << std::endl;
            return;
        }

        Mouse* next = temp->next->next;
        delete temp->next;
        temp->next = next;
    }

    // Функция поиска мышки по имени модели
    Mouse* findMouseByModel(const std::string& model) {
        Mouse* current = head;
        while (current != nullptr) {
            if (current->model == model) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    
    void printAllMice() {
        Mouse* current = head;
        while (current != nullptr) {
            std::cout << "Model: " << current->model << ", DPI: " << current->dpi << ", Color: " << current->color
                << ", Price: " << current->price << " rub., Manufacturer: " << current->manufacturer << std::endl;
            current = current->next;
        }
    }
    void sortByPrice() {
        if (!head || !head->next) return; 

        bool swapped;
        do {
            swapped = false;
            Mouse* current = head;
            while (current != nullptr && current->next != nullptr) {
                if (current->price > current->next->price) {
                    // Меняем местами данные между текущим и следующим элементом
                    std::swap(current->model, current->next->model);
                    std::swap(current->dpi, current->next->dpi);
                    std::swap(current->color, current->next->color);
                    std::swap(current->price, current->next->price);
                    std::swap(current->manufacturer, current->next->manufacturer);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);  
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    MouseList mouseList;

   
    mouseList.addMouse("Logitech G502", 16000, "чёрный", 4500, "Logitech");
    mouseList.addMouse("Razer DeathAdder Elite", 16000, "чёрный", 4999, "Razer");
    mouseList.addMouse("SteelSeries Rival 600", 12000, "чёрный", 8999, "SteelSeries");
    mouseList.addMouse("Corsair Dark Core RGB/SE", 16000, "чёрный с подсветкой", 5999, "Corsair");
    mouseList.addMouse("Logitech MX Master 3", 4000, "чёрный", 7999, "Logitech");
    mouseList.addMouse("Redragon M801", 10000, "чёрный", 1999, "Redragon");
    mouseList.addMouse("Cooler Master MM710", 16000, "белый", 2999, "Cooler Master");
    mouseList.addMouse("Razer Basilisk V3", 26000, "чёрный", 6499, "Razer");
    mouseList.addMouse("Zowie EC2-A", 3200, "чёрный", 4000, "Zowie");
    mouseList.addMouse("HyperX Pulsefire FPS Pro", 16000, "чёрный с подсветкой", 3999, "HyperX");

    
    std::cout << "All mice in the list:" << std::endl;
    mouseList.printAllMice();

    
    std::string modelToSearch = "Logitech G502";
    Mouse* foundMouse = mouseList.findMouseByModel(modelToSearch);
    if (foundMouse) {
        std::cout << "\nFound mouse: " << foundMouse->model << ", DPI: " << foundMouse->dpi << ", Price: "
            << foundMouse->price << " rub., Manufacturer: " << foundMouse->manufacturer << std::endl;
    }
    else {
        std::cout << "\nMouse not found!" << std::endl;
    }

    
    int indexToRemove = 2;
    mouseList.removeMouse(indexToRemove);
    std::cout << "\nAll mice after removing index " << indexToRemove << ":" << std::endl;
    mouseList.printAllMice();

    mouseList.sortByPrice();
    mouseList.printAllMice();

    return 0;
}
