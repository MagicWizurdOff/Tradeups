#include "Rarity.h"

Rarity::Rarity() : id(""), name(""), color("") {}

Rarity::Rarity(std::string id, std::string name, std::string color) {
    this->id = id;
    this->name = name;
    this->color = color;
}

std::string Rarity::getId() const {
    return id;
}

void Rarity::setId(const std::string& id) {
    this->id = id;
}

std::string Rarity::getName() const {
    return name;
}

void Rarity::setName(const std::string& name) {
    this->name = name;
}

std::string Rarity::getColor() const {
    return color;
}

void Rarity::setColor(const std::string& color) {
    this->color = color;
}

bool Rarity::operator==(const Rarity& rhs) const
{
    return this->id == rhs.getId() &&
        this->name == rhs.getName() &&
        this->color == rhs.getColor();
}
