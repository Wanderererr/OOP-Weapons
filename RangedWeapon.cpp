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

class Bow : public RangedWeapon {
public:
    Bow(std::string name, int damage, double weight, int maxAmmo)
        : RangedWeapon(std::move(name), damage, weight, maxAmmo, "arrows") {}

    void attack() override {
        if (currentAmmo == 0) {
            std::cout << name << "'s quiver is empty.\n";
            return;
        }
        currentAmmo--;
        std::cout << name << " looses an arrow for " << baseDamage << " damage. [" << currentAmmo << " arrows left]\n";
    }
};

class Crossbow : public RangedWeapon {
public:
    Crossbow(std::string name, int damage, double weight, int maxAmmo)
        : RangedWeapon(std::move(name), damage, weight, maxAmmo, "bolts") {}

    void attack() override {
        if (currentAmmo == 0) {
            std::cout << name << " needs to be reloaded.\n";
            return;
        }
        currentAmmo--;
        int actualDamage = static_cast<int>(baseDamage * 1.3);
        std::cout << name << " fires a bolt for " << actualDamage << " damage. [" << currentAmmo << " bolts left]\n";
    }
};
