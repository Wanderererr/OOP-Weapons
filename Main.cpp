#include <iostream>
#include "Arsenal.cpp"
#include "MeleeWeapon.cpp"
#include "RangeWeapon.cpp"

int main() {
    Arsenal arsenal;
    arsenal.addWeapon(std::make_unique<Sword>("Excalibur", 40, 2.5));
    arsenal.addWeapon(std::make_unique<Axe>("Executioner's Axe", 60, 5.0));
    arsenal.addWeapon(std::make_unique<Spear>("Spartan Spear", 35, 1.8));
    arsenal.addWeapon(std::make_unique<Pistol>("Glock-19", 25, 0.9, 10));
    arsenal.addWeapon(std::make_unique<Bow>("Elven Bow", 30, 1.2, 3));
    arsenal.addWeapon(std::make_unique<Crossbow>("Steel Crossbow", 55, 4.0, 1));

    arsenal.listWeapons();

    std::cout << "--- Melee ---\n";
    arsenal.selectWeapon("Executioner's Axe");
    arsenal.attack();
    arsenal.selectWeapon("Spartan Spear");
    arsenal.attack();

    std::cout << "\n--- Ranged ---\n";
    arsenal.selectWeapon("Elven Bow");
    arsenal.attack();
    arsenal.attack();
    arsenal.selectWeapon("Steel Crossbow");
    arsenal.attack();
    arsenal.attack(); // empty (output that there is no weapons) 

    return 0;
}
