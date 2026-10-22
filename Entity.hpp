#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <iostream>

class Entity {
public:
    virtual std::string getID() const = 0;
    virtual void input() = 0;
    virtual void display() const = 0;
    virtual std::string serialize() const = 0;
    virtual void deserialize(const std::string& line) = 0;
    virtual ~Entity() {}
};

#endif
