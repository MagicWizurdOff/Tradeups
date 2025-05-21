#include "Collection.h"

Collection::Collection() : id(""), name(""), image("") {}

Collection::Collection(std::string id, std::string name, std::string image) {
    this->id = id;
    this->name = name;
    this->image = image;
}

std::string Collection::getId() const {
    return id;
}

void Collection::setId(const std::string& id) {
    this->id = id;
}

std::string Collection::getName() const {
    return name;
}

void Collection::setName(const std::string& name) {
    this->name = name;
}

std::string Collection::getImage() const {
    return image;
}

void Collection::setImage(const std::string& image) {
    this->image = image;
}

bool Collection::operator==(const Collection& rhs) const
{
    return this->id == rhs.getId() &&
        this->name == rhs.getName() &&
        this->image == rhs.getImage();
}
