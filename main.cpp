#include "Keeper.h"
#include "Book.h"
#include "Textbook.h"
#include "Stationery.h"
#include <iostream>
#include <limits>

// Функция для отображения меню
void menu() {
    std::cout << "\n--- Меню ---\n";
    std::cout << "1. Добавить книгу\n";
    std::cout << "2. Добавить учебник\n";
    std::cout << "3. Добавить канцелярию\n";
    std::cout << "4. Удалить объект по номеру\n";
    std::cout << "5. Вывести все объекты\n";
    std::cout << "6. Сохранить в файл\n";
    std::cout << "7. Загрузить из файла\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите опцию: ";
}

int main() {
    system("chcp 1251");
    Keeper keeper;
    int choice;
    std::string filename = "data.txt";

    do {
        menu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        try {
            switch (choice) {
            case 1: {
                // Добавление обычной книги
                std::string title, author, annotation, genre;
                int year, pages;
                double price;

                std::cout << "Введите название: ";
                std::getline(std::cin, title);
                std::cout << "Введите автора: ";
                std::getline(std::cin, author);
                std::cout << "Введите год выпуска: ";
                std::cin >> year; std::cin.ignore();
                std::cout << "Введите аннотацию: ";
                std::getline(std::cin, annotation);
                std::cout << "Введите жанр: ";
                std::getline(std::cin, genre);
                std::cout << "Введите количество страниц: ";
                std::cin >> pages; std::cin.ignore();
                std::cout << "Введите цену: ";
                std::cin >> price; std::cin.ignore();

                Book* b = new Book(title, author, year, annotation, genre, pages, price);
                keeper.addObject(b);
                break;
            }
            case 2: {
                // Добавление учебника
                std::string title, author, institution;
                int year, pages, studyYear;
                double price;

                std::cout << "Введите название: ";
                std::getline(std::cin, title);
                std::cout << "Введите автора: ";
                std::getline(std::cin, author);
                std::cout << "Введите год выпуска: ";
                std::cin >> year; std::cin.ignore();
                std::cout << "Введите аннотацию: ";
                std::getline(std::cin, institution);
                std::cout << "Введите год обучения: ";
                std::cin >> studyYear; std::cin.ignore();
                std::cout << "Введите количество страниц: ";
                std::cin >> pages; std::cin.ignore();

                Textbook* t = new Textbook(title, author, year, institution, studyYear, pages);
                keeper.addObject(t);
                break;
            }
            case 3: {
                // Добавление канцеляристики
                std::string type, color, purpose;
                double price;
                int quantity;

                std::cout << "Введите тип канцелярии: ";
                std::getline(std::cin, type);
                std::cout << "Введите назначение: ";
                std::getline(std::cin, purpose);
                std::cout << "Введите цвет: ";
                std::getline(std::cin, color);
                std::cout << "Введите цену: ";
                std::cin >> price; std::cin.ignore();
                Stationery* s = new Stationery(type, color, purpose, price);
                keeper.addObject(s);
                break;
            }
            case 4: {
                int index;
                std::cout << "Введите номер для удаления (1-" << keeper.getSize() << "): ";
                std::cin >> index; std::cin.ignore();
                --index;
                keeper.removeObject(index);
                break;
            }
            case 5:
                keeper.printAll();
                break;
            case 6:
                keeper.saveToFile(filename);
                std::cout << "Данные сохранены.\n";
                break;
            case 7:
                keeper.loadFromFile(filename);
                std::cout << "Данные загружены.\n";
                break;
            case 0:
                std::cout << "Выход.\n";
                break;
            default:
                std::cout << "Некорректный выбор.\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
    } while (choice != 0);

    return 0;
}