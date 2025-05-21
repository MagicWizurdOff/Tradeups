#include "Crate.h"

Crate::Crate() : id(""), name(""), image("") {}

Crate::Crate(std::string id, std::string name, std::string image) {
    this->id = id;
    this->name = name;
    this->image = image;
}

std::string Crate::getId() const {
    return id;
}

void Crate::setId(const std::string& id) {
    this->id = id;
}

std::string Crate::getName() const {
    return name;
}

void Crate::setName(const std::string& name) {
    this->name = name;
}

std::string Crate::getImage() const {
    return image;
}

void Crate::setImage(const std::string& image) {
    this->image = image;
}

bool Crate::operator==(const Crate& rhs) const
{
    return this->id == rhs.getId() &&
        this->name == rhs.getName() &&
        this->image == rhs.getImage();
}
