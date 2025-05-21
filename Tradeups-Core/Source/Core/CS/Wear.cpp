#include "Wear.h"

Wear::Wear() : id(""), name("") {}

Wear::Wear(std::string id, std::string name) {
    this->id = id;
    this->name = name;
}

std::string Wear::getId() const {
    return id;
}

void Wear::setId(const std::string& id) {
    this->id = id;
}

std::string Wear::getName() const {
    return name;
}

void Wear::setName(const std::string& name) {
    this->name = name;
}

bool Wear::operator == (const Wear& rhs) const {
    return this->id == rhs.getId() && this->name == rhs.getName();
}
