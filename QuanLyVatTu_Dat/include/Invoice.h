#ifndef INVOICE_H
#define INVOICE_H

#include "../Entity.h"
#include <string>

class Invoice : public Entity {
private:
    std::string maHD;
    std::string ngayLap;
    std::string maNCC;
    double tongTien;
    std::string trangThai;

public:
    Invoice();
    Invoice(std::string ma, std::string ngay, std::string ncc, double tien, std::string tt);

    std::string getId() const override;
    void input() override;
    void display() const override;
    std::string toString() const override;
    void fromString(const std::string& line) override;

    static void printHeader();

    std::string getMaHD() const;
    std::string getNgayLap() const;
    std::string getMaNCC() const;
    double getTongTien() const;
    std::string getTrangThai() const;
};

#endif