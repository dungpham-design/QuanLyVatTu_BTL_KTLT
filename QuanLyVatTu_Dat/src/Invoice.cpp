#include "../include/Invoice.h"
#include "../InputHelper.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Invoice::Invoice() : tongTien(0.0) {}

Invoice::Invoice(std::string ma, std::string ngay, std::string ncc, double tien, std::string tt)
    : maHD(ma), ngayLap(ngay), maNCC(ncc), tongTien(tien), trangThai(tt) {}

std::string Invoice::getId() const {
    return maHD;
}

void Invoice::input() {
    maHD = InputHelper::getString("Nhap ma hoa don (VD: HD01): ");
    ngayLap = InputHelper::getString("Nhap ngay lap (DD/MM/YYYY): ");
    maNCC = InputHelper::getString("Nhap ma nha cung cap: ");
    tongTien = InputHelper::getDouble("Nhap tong tien thanh toan: ");
    int choice = InputHelper::getInt("Nhap trang thai (1. Da thanh toan / 2. Chua thanh toan): ");
    trangThai = (choice == 1) ? "Da thanh toan" : "Chua thanh toan";
}

void Invoice::display() const {
    std::cout << std::left << std::setw(12) << maHD
              << std::setw(15) << ngayLap
              << std::setw(15) << maNCC
              << std::setw(18) << std::fixed << std::setprecision(2) << tongTien
              << std::setw(20) << trangThai << std::endl;
}

std::string Invoice::toString() const {
    std::stringstream ss;
    ss << maHD << "|" << ngayLap << "|" << maNCC << "|" << std::fixed << std::setprecision(2) << tongTien << "|" << trangThai;
    return ss.str();
}

void Invoice::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::string strTien;
    std::getline(ss, maHD, '|');
    std::getline(ss, ngayLap, '|');
    std::getline(ss, maNCC, '|');
    std::getline(ss, strTien, '|');
    std::getline(ss, trangThai, '|');
    if (!strTien.empty()) {
        tongTien = std::stod(strTien);
    }
}

void Invoice::printHeader() {
    std::cout << std::left << std::setw(12) << "Ma Hoa Don"
              << std::setw(15) << "Ngay Lap"
              << std::setw(15) << "Ma NCC"
              << std::setw(18) << "Tong Tien"
              << std::setw(20) << "Trang Thai" << std::endl;
    std::cout << std::string(80, '-') << std::endl;
}

std::string Invoice::getMaHD() const { return maHD; }
std::string Invoice::getNgayLap() const { return ngayLap; }
std::string Invoice::getMaNCC() const { return maNCC; }
double Invoice::getTongTien() const { return tongTien; }
std::string Invoice::getTrangThai() const { return trangThai; }