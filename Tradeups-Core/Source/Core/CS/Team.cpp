#include "Team.h"

Team::Team() : id(""), name("") {}

Team::Team(std::string id, std::string name) {
    this->id = id;
    this->name = name;
}

std::string Team::getId() const {
    return id;
}

void Team::setId(const std::string& id) {
    this->id = id;
}

std::string Team::getName() const {
    return name;
}

void Team::setName(const std::string& name) {
    this->name = name;
}

bool Team::operator == (const Team& rhs) const {
    return this->id == rhs.getId() && this->name == rhs.getName();
}