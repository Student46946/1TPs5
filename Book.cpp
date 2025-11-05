#include "Book.h"

Book::Book() : title(""), author(""), year(0),
annotation(""), genre(""),
pages(0), price(0.0) {
}

Book::Book(const std::string& t, const std::string& a, int y,
    const std::string& ann, const std::string& g, int p, double pr)
    : title(t), author(a), year(y),
    annotation(ann), genre(g),
    pages(p), price(pr) {
}

Book::Book(const Book& other)
    : title(other.title), author(other.author), year(other.year),
    annotation(other.annotation), genre(other.genre),
    pages(other.pages), price(other.price) {
}

Book::~Book() {
}

void Book::print() const {
    std::cout << "\nНазвание: " << title
        << "\nАвтор: " << author
        << "\nГод выпуска: " << year
        << "\nАннотация: " << annotation
        << "\nЖанр: " << genre
        << "\nКоличество страниц: " << pages
        << "\nСтоимость: " << price << "\n";
}

void Book::save(std::ofstream& ofs) const {
    ofs << "Book\n" << title << "\n" << author << "\n" << year
        << "\n" << annotation << "\n" << genre << "\n" << pages
        << "\n" << price << "\n";
}

void Book::load(std::ifstream& ifs) {
    std::getline(ifs, title);
    std::getline(ifs, author);
    ifs >> year; ifs.ignore();
    std::getline(ifs, annotation);
    std::getline(ifs, genre);
    ifs >> pages; ifs.ignore();
    ifs >> price; ifs.ignore();
}

Base* Book::clone() const {
    return new Book(*this);
}

void Book::setName(const std::string& n) {
    title = n;
}
std::string Book::getName() const {
    return title;
}
std::string Book::getType() const {
    return "Book";
}