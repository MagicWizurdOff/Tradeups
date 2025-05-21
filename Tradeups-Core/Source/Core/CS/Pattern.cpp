#include "Pattern.h"

Pattern::Pattern() : id(""), name("") {}

Pattern::Pattern(std::string id, std::string name) {
    this->id = id;
    this->name = name;
}

std::string Pattern::getId() const {
    return id;
}

void Pattern::setId(const std::string& id) {
    this->id = id;
}

std::string Pattern::getName() const {
    return name;
}

void Pattern::setName(const std::string& name) {
    this->name = name;
}

bool Pattern::operator==(const Pattern& rhs) const
{
    return this->id == rhs.getId() &&
        this->name == rhs.getName();
}
