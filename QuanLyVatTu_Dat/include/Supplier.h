#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "../Entity.h"
#include <string>

class Supplier : public Entity {
private:
    std::string maNCC;
    std::string tenNCC;
    std::string diaChi;
    std::string sdt;

public:
    Supplier();
    Supplier(std::string ma, std::string ten, std::string dc, std::string dt);

    std::string getId() const override;
    void input() override;
    void display() const override;
    std::string toString() const override;
    void fromString(const std::string& line) override;

    static void printHeader();

    std::string getMaNCC() const;
    std::string getTenNCC() const;
    std::string getDiaChi() const;
    std::string getSdt() const;
};

#endif