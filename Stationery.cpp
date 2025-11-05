#include "Stationery.h"
#include <iostream>
#include <fstream>

Stationery::Stationery() : type(""), color(""), purpose(""), price(0.0) {
    std::cout << "Stationery default constructor\n";
}

Stationery::Stationery(const std::string& t, const std::string& c,
    const std::string& p, double pr)
    : type(t), color(c), purpose(p), price(pr) {
    std::cout << "Stationery parameterized constructor\n";
}

Stationery::Stationery(const Stationery& other)
    : type(other.type), color(other.color), purpose(other.purpose), price(other.price) {
    std::cout << "Stationery copy constructor\n";
}

Stationery::~Stationery() {
    std::cout << "Stationery destructor\n";
}

void Stationery::print() const {
    std::cout << "\nТип канцелярии: " << type
        << "\nЦвет: " << color
        << "\nНазначение: " << purpose
        << "\nЦена: " << price << "\n";
}

void Stationery::save(std::ofstream& ofs) const {
    ofs << "Stationery\n" << type << "\n" << color << "\n" << purpose << "\n" << price << "\n";
}

void Stationery::load(std::ifstream& ifs) {
    std::getline(ifs, type);
    std::getline(ifs, color);
    std::getline(ifs, purpose);
    ifs >> price; ifs.ignore();
}

Base* Stationery::clone() const {
    return new Stationery(*this);
}

void Stationery::setName(const std::string& n) {
}

std::string Stationery::getName() const {
    return type;
}

void Stationery::setType(const std::string& t) {
    type = t;
}

void Stationery::setColor(const std::string& c) {
    color = c;
}

void Stationery::setPurpose(const std::string& p) {
    purpose = p;
}

void Stationery::setPrice(double pr) {
    price = pr;
}

std::string Stationery::getType() const {
    return "Stationery";
}

std::string Stationery::getColor() const {
    return color;
}

std::string Stationery::getPurpose() const {
    return purpose;
}

double Stationery::getPrice() const {
    return price;
}