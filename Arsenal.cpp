#include "Weapon.cpp"
#include <vector>
#include <memory>
#include <iostream>

class Arsenal {
    std::vector<std::unique_ptr<Weapon>> weapons;
    Weapon* activeWeapon = nullptr;

public:
    void addWeapon(std::unique_ptr<Weapon> weapon) {
        if (!activeWeapon)
            activeWeapon = weapon.get();

        std::cout << "Added: " << weapon->getName() << "\n";
        weapons.push_back(std::move(weapon));
    }

    bool selectWeapon(const std::string& name) {
        for (const auto& w : weapons) {
            if (w->getName() == name) {
                activeWeapon = w.get();
                std::cout << "Equipped: " << name << "\n";
                return true;
            }
        }
        std::cout << "\"" << name << "\" is not in your arsenal.\n";
        return false;
    }

    void attack() {
        if (activeWeapon)
            activeWeapon->attack();
        else
            std::cout << "No weapon equipped.\n";
    }

    void listWeapons() const {
        std::cout << "\n--- Arsenal ---\n";
        for (const auto& w : weapons)
            std::cout << "  " << w->getName() << " (dmg: " << w->getDamage() << ")\n";
        std::cout << "---------------\n\n";
    }
};
