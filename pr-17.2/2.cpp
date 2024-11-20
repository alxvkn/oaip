#include <iostream>
#include <string>
#include <utility>

struct Book {
    std::string name;
    std::string author;
    int year;
    unsigned pages;
    std::string genre;

    Book* next;
};

class Library {
    Book* head;

public:
    Library() : head(nullptr) {}

    ~Library() {
        Book* current = head;
        while (current != nullptr) {
            Book* to_delete = current;
            current = current->next;
            delete to_delete;
        }
    }

    void add_book(const std::string& name, const std::string& author, int year, unsigned pages, const std::string& genre) {
        Book* new_book = new Book { name, author, year, pages, genre };

        if (!head) {
            head = new_book;
        } else {
            Book* temp = head;

            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = new_book;
        }
    }

    void print() {
        Book* b = head;
        while (b) {
            _print_book(*b);
            b = b->next;
        }
    }

    void print_by_author(const std::string& author) {
        Book* b = head;
        while (b) {
            if (b->author == author)
                _print_book(*b);
            b = b->next;
        }
    }

    void delete_by_name(const std::string& name) {
        Book* b = head;
        unsigned i = 0;

        while (b) {
            if (b->name == name) break;
            i++;
            b = b->next;
        }

        _delete_by_index(i);
    }

    void sort_by_year() {
        if (!head || !head->next) return;

        bool swapped;
        do {
            swapped = false;
            Book* b = head;
            while (b && b->next) {
                if (b->year > b->next->year) {
                    std::swap(b->year, b->next->year);
                    std::swap(b->name, b->next->name);
                    std::swap(b->author, b->next->author);
                    std::swap(b->pages, b->next->pages);
                    std::swap(b->genre, b->next->genre);
                    swapped = true;
                }
                b = b->next;
            }
        } while (swapped);
    }

private:
    void _print_book(const Book& b) {
        std::cout << "\"" << b.name << "\"" << ", " << b.author << ", " << b.year << ", " << b.pages << ", " << b.genre << std::endl;
    }

    void _delete_by_index(unsigned index) {
        if (!head) {
            std::cout << "empty list" << std::endl;
            return;
        }

        Book* b = head;

        if (index == 0) {
            head = head->next;
            delete b;
            return;
        }

        for (unsigned i = 0; b && i < index - 1; i++) {
            b = b->next;
        }

        if (!b->next) {
            std::cout << "out of bounds" << std::endl;
            return;
        }

        Book* next = b->next->next ? b->next->next : nullptr;
        delete b->next;
        b->next = next;
    }
};

int main() {
    Library l;

    l.add_book("1984", "Джордж Оруэлл", 1949, 328, "антиутопия");
    l.add_book("Убить пересмешника", "Харпер Ли", 1960, 281, "драма");
    l.add_book("Война и мир", "Лев Толстой", 1869, 1200, "исторический роман");
    l.add_book("Гарри Поттер и философский камень", "Дж. К. Роулинг", 1997, 336, "фэнтези");
    l.add_book("Преступление и наказание", "Фёдор Достоевский", 1866, 500, "классика");
    l.add_book("Анна Каренина", "Лев Толстой", 1877, 864, "драма");
    l.add_book("Мастер и Маргарита", "Михаил Булгаков", 1966, 448, "философский роман");
    l.add_book("Хоббит", "Дж. Р. Р. Толкин", 1937, 310, "фэнтези");
    l.add_book("Алхимик", "Пауло Коэльо", 1988, 208, "философский роман");
    l.add_book("Джейн Эйр", "Шарлотта Бронте", 1847, 624, "роман");

    l.print();
    l.delete_by_name("1984");
    std::cout << std::endl;
    std::cout << "after deleting 1984" << std::endl;
    l.print();

    std::cout << std::endl;
    std::cout << "print_by_author(\"Лев Толстой\")"<< std::endl;
    l.print_by_author("Лев Толстой");

    std::cout << std::endl;
    std::cout << "after sorting by year" << std::endl;
    l.sort_by_year();
    l.print();
}
