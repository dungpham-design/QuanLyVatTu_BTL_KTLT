#ifndef INVOICE_HPP
#define INVOICE_HPP

#include "Entity.hpp"

class Invoice : public Entity {
private:
    std::string maHD;
    std::string maNCC;
    std::string ngayLap;
    double tongTien;

public:
    Invoice();
    Invoice(std::string mahd, std::string mancc, std::string ngay, double tien);

    std::string getID() const override { return maHD; }
    std::string getMaNCC() const { return maNCC; }
    void input() override;
    void display() const override;
    std::string serialize() const override;
    void deserialize(const std::string& line) override;
};

#endif
