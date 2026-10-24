#ifndef INVOICE_MENU_H
#define INVOICE_MENU_H

#include "../Repository.h"
#include "Invoice.h"
#include "../InputHelper.h"
#include <iostream>

class InvoiceMenu {
private:
    Repository<Invoice>& repo;
public:
    InvoiceMenu(Repository<Invoice>& r) : repo(r) {}

    void run() {
        int choice;
        do {
            std::cout << "\n--- QUAN LY HOA DON THANH TOAN (UC10) ---\n";
            std::cout << "1. Hien thi danh sach\n";
            std::cout << "2. Them hoa don\n";
            std::cout << "3. Tim kiem theo ma\n";
            std::cout << "4. Xoa hoa don\n";
            std::cout << "0. Quay lai\n";
            choice = InputHelper::getInt("Lua chon cua ban: ");

            switch (choice) {
                case 1:
                    Invoice::printHeader();
                    repo.displayAll();
                    break;
                case 2: {
                    Invoice inv;
                    inv.input();
                    repo.add(inv);
                    repo.saveToFile("data/invoices.txt");
                    std::cout << "Them hoa don thanh cong!\n";
                    break;
                }
                case 3: {
                    std::string id = InputHelper::getString("Nhap ma hoa don can tim: ");
                    Invoice* inv = repo.findById(id);
                    if (inv) {
                        Invoice::printHeader();
                        inv->display();
                    } else {
                        std::cout << "Khong tim thay hoa don!\n";
                    }
                    break;
                }
                case 4: {
                    std::string id = InputHelper::getString("Nhap ma hoa don can xoa: ");
                    if (repo.remove(id)) {
                        repo.saveToFile("data/invoices.txt");
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