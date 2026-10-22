#ifndef SUPPLIER_HPP
#define SUPPLIER_HPP

#include "Entity.hpp"

class Supplier : public Entity {
private:
    std::string maNCC;
    std::string tenNCC;
    std::string diaChi;
    std::string sdt;

public:
    Supplier();
    Supplier(std::string ma, std::string ten, std::string dc, std::string dt);

    std::string getID() const override { return maNCC; }
    void input() override;
    void display() const override;
    std::string serialize() const override;
    void deserialize(const std::string& line) override;
    
    std::string getTenNCC() const { return tenNCC; }
};

#endif
