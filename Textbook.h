#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include "Base.h"
#include <string>

class Textbook : public Base {
private:
    std::string title;       // Название
    std::string author;      // Автор
    int year;                // Год выпуска
    std::string institution; // Предназначено для какого учебного заведения
    int studyYear;           // Год обучения
    int pages;               // Объем страниц

public:
    std::string getType() const;
    Textbook();
    Textbook(const std::string&, const std::string&, int, const std::string&, int, int);
    Textbook(const Textbook&);
    ~Textbook();

    void print() const override;
    void save(std::ofstream& ofs) const override;
    void load(std::ifstream& ifs) override;
    Base* clone() const override;

    void setName(const std::string&) override;
    std::string getName() const override;

    // сеттеры
    void setTitle(const std::string&);
    void setAuthor(const std::string&);
    void setYear(int);
    void setInstitution(const std::string&);
    void setStudyYear(int);
    void setPages(int);


    // геттеры
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getInstitution() const;
    int getStudyYear() const;
    int getPages() const;

};

#endif