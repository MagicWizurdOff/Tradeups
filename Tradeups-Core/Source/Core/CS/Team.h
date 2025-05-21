#pragma once
#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <string>
using string = std::string;
class Team {
public:
    Team();
    Team(std::string id, std::string name);

    std::string getId() const;
    void setId(const std::string& id);

    std::string getName() const;
    void setName(const std::string& name);

    bool operator == (const Team& rhs) const;

private:
    std::string id;
    std::string name;
};

#endif
