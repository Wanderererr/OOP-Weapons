#pragma once
#include "Weapon.cpp"
#include <iostream>
#include <algorithm>

class MeleeWeapon : public Weapon {
protected:
    int durability;

public:
    MeleeWeapon(std::string name, int damage, double weight, int durability)
        : Weapon(std::move(name), damage, weight), durability(durability) {}

    void repair(int amount) {
        durability = std::min(100, durability + amount);
        std::cout << name << " repaired. Durability: " << durability << "%\n";
    }
    int getDurability() const { return durability; }
};

class Sword : public MeleeWeapon {
public:
    Sword(std::string name, int damage, double weight)
        : MeleeWeapon(std::move(name), damage, weight, 100) {}

    void attack() override {
        if (durability <= 0) {
            std::cout << name << " is too dull to fight with.\n";
            return;
        }
        durability -= 10;
        std::cout << name << " slashes for " << baseDamage << " damage. [Durability: " << durability << "%]\n";
    }
};

class Axe : public MeleeWeapon {
public:
    Axe(std::string name, int damage, double weight)
        : MeleeWeapon(std::move(name), damage, weight, 100) {}

    void attack() override {
        if (durability <= 0) {
            std::cout << name << "'s shaft has snapped.\n";
            return;
        }
        durability -= 20;
        int actualDamage = static_cast<int>(baseDamage * 1.5);
        std::cout << name << " cleaves for " << actualDamage << " damage. [Durability: " << durability << "%]\n";
    }
};

class Spear : public MeleeWeapon {
public:
    Spear(std::string name, int damage, double weight)
        : MeleeWeapon(std::move(name), damage, weight, 100) {}

    void attack() override {
        if (durability <= 0) {
            std::cout << name << "'s tip is too bent to pierce anything.\n";
            return;
        }
        durability -= 5;
        std::cout << name << " thrusts for " << baseDamage << " piercing damage. [Durability: " << durability << "%]\n";
    }
};
class BrassKnuckles : public MeleeWeapon {
public:
    BrassKnuckles(std::string name, int damage, double weight)
        : MeleeWeapon(std::move(name), damage, weight, 100) {}

    void attack() override {
        if (durability <= 0) {
            std::cout << name << "'s straps have snapped.\n";
            return;
        }
        durability -= 2;
        std::cout << name << " connects for " << baseDamage << " bludgeoning damage. [Durability: " << durability << "%]\n";
    }
};
