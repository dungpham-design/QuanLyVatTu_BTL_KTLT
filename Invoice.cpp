#include "Invoice.hpp"
#include <sstream>
#include <iomanip>

Invoice::Invoice() : tongTien(0.0) {}

Invoice::Invoice(std::string mahd, std::string mancc, std::string ngay, double tien)
    : maHD(mahd), maNCC(mancc), ngayLap(ngay), tongTien(tien) {}

void Invoice::input() {
    std::cout << "Nhap ma hoa don (VD: HD001): ";
    std::cin >> maHD;
    std::cout << "Nhap ma nha cung cap tham chieu (NCC): ";
    std::cin >> maNCC;
    std::cout << "Nhap ngay lap (DD/MM/YYYY): ";
    std::cin >> ngayLap;
    std::cout << "Nhap tong tien thanh toan: ";
    std::cin >> tongTien;
}

void Invoice::display() const {
    std::cout << std::left << std::setw(10) << maHD 
              << std::setw(15) << maNCC 
              << std::setw(15) << ngayLap 
              << std::setw(15) << std::fixed << std::setprecision(0) << tongTien << std::endl;
}

std::string Invoice::serialize() const {
    return maHD + "|" + maNCC + "|" + ngayLap + "|" + std::to_string(tongTien);
}

void Invoice::deserialize(const std::string& line) {
    std::stringstream ss(line);
    std::string tienStr;
    std::getline(ss, maHD, '|');
    std::getline(ss, maNCC, '|');
    std::getline(ss, ngayLap, '|');
    std::getline(ss, tienStr, '|');
    if (!tienStr.empty()) {
        tongTien = std::stod(tienStr);
    }
}
