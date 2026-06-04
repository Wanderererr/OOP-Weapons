#include "Weapon.cpp"
#include <iostream>

class RangedWeapon : public Weapon {
protected:
    int maxAmmo;
    int currentAmmo;
    std::string ammoType;

public:
    RangedWeapon(std::string name, int damage, double weight, int maxAmmo, std::string ammoType)
        : Weapon(std::move(name), damage, weight),
          maxAmmo(maxAmmo), currentAmmo(maxAmmo), ammoType(std::move(ammoType)) {}

    void reload() {
        currentAmmo = maxAmmo;
        std::cout << name << " reloaded with " << currentAmmo << " " << ammoType << ".\n";
    }

    int getAmmo() const { return currentAmmo; }
};

class Pistol : public RangedWeapon {
public:
    Pistol(std::string name, int damage, double weight, int maxAmmo)
        : RangedWeapon(std::move(name), damage, weight, maxAmmo, "bullets") {}

    void attack() override {
        if (currentAmmo == 0) {
            std::cout << name << " clicks on an empty chamber.\n";
            return;
        }
        currentAmmo--;
        std::cout << name << " fires for " << baseDamage << " damage. [" << currentAmmo << " rounds left]\n";
    }
};

class Rifle : public RangedWeapon {
public:
    Rifle(std::string name, int damage, double weight, int maxAmmo)
        : RangedWeapon(std::move(name), damage, weight, maxAmmo, "rounds") {}

    void attack() override {
        if (currentAmmo == 0) {
            std::cout << name << " is empty, reload first.\n";
            return;
        }
        currentAmmo -= 3; // burst of 3
        if (currentAmmo < 0) currentAmmo = 0;
        std::cout << name << " fires a burst for " << baseDamage * 3 << " damage. [" << currentAmmo << " rounds left]\n";
    }
};
