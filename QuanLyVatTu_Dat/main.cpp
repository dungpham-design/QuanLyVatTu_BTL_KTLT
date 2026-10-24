#include <iostream>
#include "Repository.h"
#include "include/Supplier.h"
#include "include/Invoice.h"
#include "include/SupplierMenu.h"
#include "include/InvoiceMenu.h"
#include "InputHelper.h"

int main() {
    Repository<Supplier> supplierRepo;
    supplierRepo.loadFromFile("data/suppliers.txt");

    Repository<Invoice> invoiceRepo;
    invoiceRepo.loadFromFile("data/invoices.txt");

    SupplierMenu supplierMenu(supplierRepo);
    InvoiceMenu invoiceMenu(invoiceRepo);

    int choice;
    do {
        std::cout << "\n================ CHUONG TRINH CHINH ================\n";
        std::cout << "Sinh vien: Mai Tat Dat - MSSV: B24DCVT064\n";
        std::cout << "1. Quan ly Nha cung cap (UC03)\n";
        std::cout << "2. Quan ly Hoa don thanh toan (UC10)\n";
        std::cout << "0. Thoat chuong trinh\n";
        std::cout << "====================================================\n";
        choice = InputHelper::getInt("Nhap lua chon cua ban: ");

        switch (choice) {
            case 1:
                supplierMenu.run();
                break;
            case 2:
                invoiceMenu.run();
                break;
            case 0:
                std::cout << "Tam biet!\n";
                break;
            default:
                std::cout << "Lua chon khong hop le! Vui long chon lai.\n";
        }
    } while (choice != 0);

    return 0;
}