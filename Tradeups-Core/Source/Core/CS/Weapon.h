#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>
using string = std::string;
class Weapon {
public:
    Weapon();
    Weapon(std::string id, int weapon_id, std::string name);

    std::string getId() const;
    void setId(const std::string& id);

    int getWeaponId() const;
    void setWeaponId(int weapon_id);

    std::string getName() const;
    bool operator == (const Weapon& rhs) const;
    void setName(const std::string& name);


private:
    std::string id;
    int weapon_id;
    std::string name;
};

#endif

