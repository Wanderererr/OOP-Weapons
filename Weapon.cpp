#pragma once
#include <string>

class Weapon {
protected:
    std::string name;
    int baseDamage;
    double weight;

public:
    Weapon(std::string name, int damage, double weight)
        : name(std::move(name)), baseDamage(damage), weight(weight) {}

    virtual ~Weapon() = default;
    virtual void attack() = 0;

    std::string getName() const { return name; }
    int getDamage() const { return baseDamage; }
    double getWeight() const { return weight; }
};
