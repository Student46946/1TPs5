#include "Base.h"
#include <string>

class Stationery : public Base {
private:
    std::string type;       // Òèï êàíöåëÿðèè
    std::string color;      // Öâåò
    std::string purpose;    // Íàçíà÷åíèå
    double price;           // Ñòîèìîñòü

public:
    
    Stationery();
    Stationery(const std::string&, const std::string&, const std::string&, double);
    Stationery(const Stationery&);
    ~Stationery();

    void print() const override;
    void save(std::ofstream& ofs) const override;
    void load(std::ifstream& ifs) override;
    Base* clone() const override;

    void setName(const std::string&) override;
    std::string getName() const override;

    // ñåòòåðû
    void setType(const std::string&);
    void setColor(const std::string&);
    void setPurpose(const std::string&);
    void setPrice(double);

    // ãåòòåðû
    std::string getType() const;
    std::string getColor() const;
    std::string getPurpose() const;
    double getPrice() const;
};
