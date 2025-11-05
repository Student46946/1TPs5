#ifndef BOOK_H
#define BOOK_H

#include "Base.h"

class Book : public Base {
private:
    std::string title;
    std::string author;
    int year;
    std::string annotation;
    std::string genre;
    int pages;
    double price;

public:
    std::string getType() const;
    Book(); // дефолт
    Book(const std::string&, const std::string&, int, const std::string&,
        const std::string&, int, double);
    Book(const Book&);
    ~Book();

    void print() const override;
    void save(std::ofstream& ofs) const override;
    void load(std::ifstream& ifs) override;
    Base* clone() const override;

    void setName(const std::string&) override;
    std::string getName() const override;

    // сеттеры для других полей (позже)
    void setTitle(const std::string&);
    void setAuthor(const std::string&);
    void setYear(int);
    void setAnnotation(const std::string&);
    void setGenre(const std::string&);
    void setPages(int);
    void setPrice(double);

    // геттеры
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getAnnotation() const;
    std::string getGenre() const;
    int getPages() const;
    double getPrice() const;
};

#endif