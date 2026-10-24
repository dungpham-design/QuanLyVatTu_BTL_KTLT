#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H

#include <iostream>
#include <string>
#include <limits>

class InputHelper {
public:
    static std::string getString(std::string prompt = "") {
        if (!prompt.empty()) std::cout << prompt;
        std::string s;
        std::getline(std::cin >> std::ws, s);
        return s;
    }

    static int getInt(std::string prompt = "") {
        int val;
        while (true) {
            if (!prompt.empty()) std::cout << prompt;
            if (std::cin >> val) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return val;
            }
            std::cout << "Loi! Vui long nhap lai so nguyen: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    static double getDouble(std::string prompt = "") {
        double val;
        while (true) {
            if (!prompt.empty()) std::cout << prompt;
            if (std::cin >> val) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return val;
            }
            std::cout << "Loi! Vui long nhap lai so thuc: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
};

#endif