#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

class Base {
public:
    Base() {
    }
    virtual ~Base() {
    }

    Base(const Base&) {
    }

    virtual void print() const = 0;
    virtual void save(std::ofstream& ofs) const = 0;
    virtual void load(std::ifstream& ifs) = 0;
    virtual Base* clone() const = 0;
    virtual std::string getType() const = 0;

    virtual void setName(const std::string&) = 0;
    virtual std::string getName() const = 0;
};

#endif