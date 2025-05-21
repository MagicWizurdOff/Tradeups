#include "Weapon.h"

Weapon::Weapon() : id(""), weapon_id(0), name("") {}

Weapon::Weapon(std::string id, int weapon_id, std::string name) {
    this->id = id;
    this->weapon_id = weapon_id;
    this->name = name;
}

std::string Weapon::getId() const {
    return id;
}

void Weapon::setId(const std::string& id) {
    this->id = id;
}

int Weapon::getWeaponId() const {
    return weapon_id;
}

void Weapon::setWeaponId(int weapon_id) {
    this->weapon_id = weapon_id;
}

std::string Weapon::getName() const {
    return name;
}

void Weapon::setName(const std::string& name) {
    this->name = name;
}

bool Weapon::operator == (const Weapon& rhs) const {
    return this->id == rhs.getId() && this->name == rhs.getName();
}