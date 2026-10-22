#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "VatTu.hpp"
#include "PhieuNhap.hpp"

template <typename T>
void loadFromFile(std::vector<T>& list, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        T item;
        item.deserialize(line);
        list.push_back(item);
    }
    file.close();
}

template <typename T>
void saveToFile(const std::vector<T>& list, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& item : list) {
        file << item.serialize() << "\n";
    }
    file.close();
}

void vatTuMenu(std::vector<VatTu>& dsVatTu) {
    int choice;
    do {
        std::cout << "\n=== QUAN LY VAT TU ===\n";
        std::cout << "1. Them vat tu moi\n";
        std::cout << "2. Xem danh sach vat tu\n";
        std::cout << "3. Quay lai menu chinh\n";
        std::cout << "Nhap lua chon: ";
        std::cin >> choice;

        if (choice == 1) {
            VatTu vt;
            vt.input();
            dsVatTu.push_back(vt);
            saveToFile(dsVatTu, "data/vattu.txt");
            std::cout << "Them vat tu thanh cong va da luu file!\n";
        } else if (choice == 2) {
            std::cout << std::left << std::setw(10) << "Ma VT" 
                      << std::setw(30) << "Ten Vat Tu" 
                      << std::setw(15) << "DVT" 
                      << std::setw(15) << "So Luong Ton" << std::endl;
            std::cout << std::string(70, '-') << std::endl;
            for (const auto& vt : dsVatTu) {
                vt.display();
            }
        }
    } while (choice != 3);
}

void phieuNhapMenu(std::vector<PhieuNhap>& dsPhieuNhap, const std::vector<VatTu>& dsVatTu) {
    int choice;
    do {
        std::cout << "\n=== QUAN LY PHIEU NHAP ===\n";
        std::cout << "1. Them phieu nhap moi\n";
        std::cout << "2. Xem danh sach phieu nhap\n";
        std::cout << "3. Quay lai menu chinh\n";
        std::cout << "Nhap lua chon: ";
        std::cin >> choice;

        if (choice == 1) {
            PhieuNhap pn;
            pn.input();
            
            // Kiem tra rang buoc khoa ngoai: Ma vat tu phai ton tai
            bool found = false;
            for (const auto& vt : dsVatTu) {
                if (vt.getID() == pn.getMaVT()) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Loi: Ma vat tu khong ton tai trong he thong! Khong the lap phieu nhap.\n";
            } else {
                dsPhieuNhap.push_back(pn);
                saveToFile(dsPhieuNhap, "data/phieunhap.txt");
                std::cout << "Them phieu nhap thanh cong va da luu file!\n";
            }
        } else if (choice == 2) {
            std::cout << std::left << std::setw(10) << "Ma PN" 
                      << std::setw(12) << "Ma VT" 
                      << std::setw(15) << "Ngay Nhap" 
                      << std::setw(12) << "So Luong" 
                      << std::setw(15) << "Don Gia" << std::endl;
            std::cout << std::string(64, '-') << std::endl;
            for (const auto& pn : dsPhieuNhap) {
                pn.display();
            }
        }
    } while (choice != 3);
}

int main() {
    system("mkdir -p data");

    std::vector<VatTu> dsVatTu;
    std::vector<PhieuNhap> dsPhieuNhap;

    loadFromFile(dsVatTu, "data/vattu.txt");
    loadFromFile(dsPhieuNhap, "data/phieunhap.txt");

    int choice;
    do {
        std::cout << "\n================ CHUONG TRINH CHINH (SV3) ================\n";
        std::cout << "Sinh vien: Mai Tat Dat - MSSV: B24DCVT064\n";
        std::cout << "1. Quan ly Vat tu\n";
        std::cout << "2. Quan ly Phieu nhap\n";
        std::cout << "0. Thoat chuong trinh\n";
        std::cout << "=========================================================\n";
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                vatTuMenu(dsVatTu);
                break;
            case 2:
                phieuNhapMenu(dsPhieuNhap, dsVatTu);
                break;
            case 0:
                std::cout << "Tam biet!\n";
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long chon lai!\n";
        }
    } while (choice != 0);

    return 0;
}
