#include "../include/Supplier.h"
#include "../InputHelper.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Supplier::Supplier() {}

Supplier::Supplier(std::string ma, std::string ten, std::string dc, std::string dt)
    : maNCC(ma), tenNCC(ten), diaChi(dc), sdt(dt) {}

std::string Supplier::getId() const {
    return maNCC;
}

void Supplier::input() {
    maNCC = InputHelper::getString("Nhap ma nha cung cap (VD: NCC01): ");
    tenNCC = InputHelper::getString("Nhap ten nha cung cap: ");
    diaChi = InputHelper::getString("Nhap dia chi: ");
    sdt = InputHelper::getString("Nhap so dien thoai: ");
}

void Supplier::display() const {
    std::cout << std::left << std::setw(10) << maNCC
              << std::setw(35) << tenNCC
              << std::setw(30) << diaChi
              << std::setw(15) << sdt << std::endl;
}

std::string Supplier::toString() const {
    return maNCC + "|" + tenNCC + "|" + diaChi + "|" + sdt;
}

void Supplier::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::getline(ss, maNCC, '|');
    std::getline(ss, tenNCC, '|');
    std::getline(ss, diaChi, '|');
    std::getline(ss, sdt, '|');
}

void Supplier::printHeader() {
    std::cout << std::left << std::setw(10) << "Ma NCC"
              << std::setw(35) << "Ten Nha Cung Cap"
              << std::setw(30) << "Dia Chi"
              << std::setw(15) << "So Dien Thoai" << std::endl;
    std::cout << std::string(90, '-') << std::endl;
}

std::string Supplier::getMaNCC() const { return maNCC; }
std::string Supplier::getTenNCC() const { return tenNCC; }
std::string Supplier::getDiaChi() const { return diaChi; }
std::string Supplier::getSdt() const { return sdt; }