#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"
#include <iostream>
#include <fstream>
#include <string>

class Keeper {
private:
    Base** items;
    int size;
    int capacity;

    void resize();

public:
    Keeper();
    ~Keeper();

    void addObject(Base* obj);
    void removeObject(int index);
    void printAll() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    int getSize() const;
};

#endif