#include "Keeper.h"
#include "Book.h"
#include "Textbook.h"
#include "Stationery.h"
Keeper::Keeper() : size(0), capacity(10) {
    items = new Base * [capacity];
    
}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i)
        delete items[i];
    delete[] items;
    
}

void Keeper::resize() {
    capacity *= 2;
    Base** newItems = new Base * [capacity];
    for (int i = 0; i < size; ++i)
        newItems[i] = items[i];
    delete[] items;
    items = newItems;
}

void Keeper::addObject(Base* obj) {
    if (size >= capacity) resize();
    items[size++] = obj;
}

void Keeper::removeObject(int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Такой нет");
    delete items[index];
    for (int i = index; i < size - 1; ++i)
        items[i] = items[i + 1];
    --size;
}

void Keeper::printAll() const {
    // 1. Вывод книг
    std::cout << "\n\nКниги" << ":\n\n";
    for (int i = 0; i < size; ++i) {
        if (items[i]->getType() == "Book") {
            std::cout << "#" << i + 1 << ":\n";
            items[i]->print();
            std::cout << "---------------------\n";
        }
    }
    std::cout << "\n\nУчебники" << ":\n\n";
    // 2. Вывод учебников
    for (int i = 0; i < size; ++i) {
        if (items[i]->getType() == "Textbook") {
            std::cout << "#" << i + 1 << ":\n";
            items[i]->print();
            std::cout << "---------------------\n";
        }
    }
    std::cout << "\n\nКанцелярия" << ":\n\n";
    // 3. Вывод канцелярии
    for (int i = 0; i < size; ++i) {
        if (items[i]->getType() == "Stationery") {
            std::cout << "#" << i + 1 << ":\n";
            items[i]->print();
            std::cout << "---------------------\n";
        }
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream ofs(filename);
    if (!ofs) throw std::runtime_error("Cannot open file");
    ofs << size << "\n";
    for (int i = 0; i < size; ++i) {
        items[i]->save(ofs);
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs) throw std::runtime_error("Ошибка");
    // очищаем текущие объекты
    for (int i = 0; i < size; ++i) delete items[i];
    delete[] items;

    size = 0;
    int count;
    ifs >> count; ifs.ignore();
    items = new Base * [capacity];

    for (int i = 0; i < count; ++i) {
        std::string type;
        std::getline(ifs, type);
        Base* obj = nullptr;
        if (type == "Book") {
            obj = new Book();
        }
        if (type == "Textbook") {
            obj = new Textbook();
        }
        if (type == "Stationery") {
            obj = new Stationery();
        }
        // при необходимости добавить другие типы
        if (obj) {
            obj->load(ifs);
            addObject(obj);
        }
    }
    std::cout << "Loaded " << size << " objects.\n";
}

int Keeper::getSize() const {
    return size;
}