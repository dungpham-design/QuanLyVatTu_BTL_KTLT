#ifndef SUPPLIER_MENU_H
#define SUPPLIER_MENU_H

#include "../Repository.h"
#include "Supplier.h"
#include "../InputHelper.h"
#include <iostream>

class SupplierMenu {
private:
    Repository<Supplier>& repo;
public:
    SupplierMenu(Repository<Supplier>& r) : repo(r) {}

    void run() {
        int choice;
        do {
            std::cout << "\n--- QUAN LY NHA CUNG CAP (UC03) ---\n";
            std::cout << "1. Hien thi danh sach\n";
            std::cout << "2. Them nha cung cap\n";
            std::cout << "3. Tim kiem theo ma\n";
            std::cout << "4. Xoa nha cung cap\n";
            std::cout << "0. Quay lai\n";
            choice = InputHelper::getInt("Lua chon cua ban: ");

            switch (choice) {
                case 1:
                    Supplier::printHeader();
                    repo.displayAll();
                    break;
                case 2: {
                    Supplier s;
                    s.input();
                    repo.add(s);
                    repo.saveToFile("data/suppliers.txt");
                    std::cout << "Them nha cung cap thanh cong!\n";
                    break;
                }
                case 3: {
                    std::string id = InputHelper::getString("Nhap ma NCC can tim: ");
                    Supplier* s = repo.findById(id);
                    if (s) {
                        Supplier::printHeader();
                        s->display();
                    } else {
                        std::cout << "Khong tim thay nha cung cap!\n";
                    }
                    break;
                }
                case 4: {
                    std::string id = InputHelper::getString("Nhap ma NCC can xoa: ");
                    if (repo.remove(id)) {
                        repo.saveToFile("data/suppliers.txt");
                        std::cout << "Xoa thanh cong!\n";
                    } else {
                        std::cout << "Khong tim thay ma de xoa!\n";
                    }
                    break;
                }
                case 0:
                    break;
                default:
                    std::cout << "Lua chon khong hop le!\n";
            }
        } while (choice != 0);
    }
};

#endif