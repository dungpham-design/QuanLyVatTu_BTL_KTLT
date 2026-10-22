#include "Supplier.hpp"
#include <sstream>
#include <iomanip>

Supplier::Supplier() {}

Supplier::Supplier(std::string ma, std::string ten, std::string dc, std::string dt)
    : maNCC(ma), tenNCC(ten), diaChi(dc), sdt(dt) {}

void Supplier::input() {
    std::cout << "Nhap ma nha cung cap (VD: NCC01): ";
    std::cin >> maNCC;
    std::cin.ignore();
    std::cout << "Nhap ten nha cung cap: ";
    std::getline(std::cin, tenNCC);
    std::cout << "Nhap dia chi: ";
    std::getline(std::cin, diaChi);
    std::cout << "Nhap so dien thoai: ";
    std::cin >> sdt;
}

void Supplier::display() const {
    std::cout << std::left << std::setw(10) << maNCC 
              << std::setw(30) << tenNCC 
              << std::setw(20) << diaChi 
              << std::setw(15) << sdt << std::endl;
}

std::string Supplier::serialize() const {
    return maNCC + "|" + tenNCC + "|" + diaChi + "|" + sdt;
}

void Supplier::deserialize(const std::string& line) {
    std::stringstream ss(line);
    std::getline(ss, maNCC, '|');
    std::getline(ss, tenNCC, '|');
    std::getline(ss, diaChi, '|');
    std::getline(ss, sdt, '|');
}
