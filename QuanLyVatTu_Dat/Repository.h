#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

template <typename T>
class Repository {
private:
    std::vector<T> items;
public:
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) return;
        items.clear();
        std::string line;
        while (std::getline(file, line)) {
            if (!line.empty()) {
                T item;
                item.fromString(line);
                items.push_back(item);
            }
        }
        file.close();
    }

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) return;
        for (const auto& item : items) {
            file << item.toString() << "\n";
        }
        file.close();
    }

    void add(const T& item) {
        items.push_back(item);
    }

    bool remove(const std::string& id) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getId() == id) {
                items.erase(it);
                return true;
            }
        }
        return false;
    }

    T* findById(const std::string& id) {
        for (auto& item : items) {
            if (item.getId() == id) {
                return &item;
            }
        }
        return nullptr;
    }

    void displayAll() const {
        for (const auto& item : items) {
            item.display();
        }
    }

    std::vector<T>& getAll() {
        return items;
    }
};

#endif