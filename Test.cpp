#include <iostream>
#include <Arsenal.cpp> 
#include <MeleeWeapon.cpp> 
#include <RangedWeaon.cpp> 
#include <Weapon.cpp> 

void testInitialization() {
    Sword s("Sting", 30, 1.5);
    assert(s.getName() == "Sting");
    assert(s.getDamage() == 30);
    assert(s.getDurability() == 100);
 
    Bow b("Longbow", 25, 1.2, 8);
    assert(b.getAmmo() == 8);
 
    std::cout << "Test 1 passed: Initialization\n";
}
 
void testDurabilityDecay() {
    Axe axe("Test Axe", 50, 4.0);
 
    axe.attack();
    assert(axe.getDurability() == 80);
 
    axe.attack();
    assert(axe.getDurability() == 60);
 
    std::cout << "Test 2 passed: Durability decay\n";
}
 
void testRepairCap() {
    Spear spear("Test Spear", 35, 2.0);
 
    spear.attack(); // loses 5
    spear.repair(50); // should cap at 100
    assert(spear.getDurability() == 100);
 
    std::cout << "Test 3 passed: Repair cap\n";
}
 
void testAmmoTracking() {
    Pistol p("Test Pistol", 20, 0.8, 3);
 
    p.attack(); assert(p.getAmmo() == 2);
    p.attack(); assert(p.getAmmo() == 1);
    p.attack(); assert(p.getAmmo() == 0);
    p.attack(); assert(p.getAmmo() == 0); // empty, should not go below 0
 
    p.reload();
    assert(p.getAmmo() == 3);
 
    std::cout << "Test 4 passed: Ammo tracking\n";
}
 
void testArsenalFallback() {
    Arsenal a;
    a.attack(); // empty, should not crash
 
    a.addWeapon(std::make_unique<Sword>("Blade", 40, 2.0));
    bool found = a.selectWeapon("Plasma Rifle");
    assert(!found);
 
    std::cout << "Test 5 passed: Arsenal fallback\n";
}
 
int main() {
    std::cout << "Running tests...\n\n";
    testInitialization();
    testDurabilityDecay();
    testRepairCap();
    testAmmoTracking();
    testArsenalFallback();
    std::cout << "\nAll tests passed.\n";
    return 0;
}
 
