#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
public:
    virtual std::string getId() const = 0;
    virtual void input() = 0;
    virtual void display() const = 0;
    virtual std::string toString() const = 0;
    virtual void fromString(const std::string& line) = 0;
    virtual ~Entity() {}
};

#endif