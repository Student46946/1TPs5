#include "Textbook.h"
#include <iostream>
#include <fstream>

Textbook::Textbook() : title(""), author(""), year(0),
institution(""), studyYear(0), pages(0) {
}

Textbook::Textbook(const std::string& t, const std::string& a, int y,
    const std::string& inst, int sy, int p)
    : title(t), author(a), year(y),
    institution(inst), studyYear(sy), pages(p) {
}

Textbook::Textbook(const Textbook& other)
    : title(other.title), author(other.author), year(other.year),
    institution(other.institution), studyYear(other.studyYear),
    pages(other.pages) {
}

Textbook::~Textbook() {
}

void Textbook::print() const {
    std::cout << "\nНазвание: " << title
        << "\nАвтор: " << author
        << "\nГод выпуска: " << year
        << "\nИнститут: " << institution
        << "\nГод обучения: " << studyYear
        << "\nКоличество страниц: " << pages << "\n";
}

void Textbook::save(std::ofstream& ofs) const {
    ofs << "Textbook\n" << title << "\n" << author << "\n" << year
        << "\n" << institution << "\n" << studyYear << "\n" << pages
        << "\n";
}

void Textbook::load(std::ifstream& ifs) {
    std::getline(ifs, title);
    std::getline(ifs, author);
    ifs >> year; ifs.ignore();
    std::getline(ifs, institution);
    ifs >> studyYear; ifs.ignore();
    ifs >> pages; ifs.ignore();

}

Base* Textbook::clone() const {
    return new Textbook(*this);
}

void Textbook::setName(const std::string& n) {
    title = n;
}
std::string Textbook::getName() const {
    return title;
}

// сеттеры
void Textbook::setTitle(const std::string& t) {
    title = t;
}
void Textbook::setAuthor(const std::string& a) {
    author = a;
}
void Textbook::setYear(int y) {
    year = y;
}
void Textbook::setInstitution(const std::string& inst) {
    institution = inst;
}
void Textbook::setStudyYear(int sy) {
    studyYear = sy;
}
void Textbook::setPages(int p) {
    pages = p;
}


// геттеры
std::string Textbook::getTitle() const {
    return title;
}
std::string Textbook::getAuthor() const {
    return author;
}
int Textbook::getYear() const {
    return year;
}
std::string Textbook::getInstitution() const {
    return institution;
}
int Textbook::getStudyYear() const {
    return studyYear;
}
int Textbook::getPages() const {
    return pages;
}
std::string Textbook::getType() const {
    return "Textbook";
}
