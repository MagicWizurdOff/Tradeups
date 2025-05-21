#include "Category.h"

Category::Category() : id(""), name("") {}

Category::Category(std::string id, std::string name) {
    this->id = id;
    this->name = name;
}

std::string Category::getId() const {
    return id;
}

void Category::setId(const std::string& id) {
    this->id = id;
}

std::string Category::getName() const {
    return name;
}

void Category::setName(const std::string& name) {
    this->name = name;
}

bool Category::operator==(const Category& rhs) const
{
    return this->id == rhs.getId() &&
        this->name == rhs.getName();
}
