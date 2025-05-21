#pragma once
#ifndef WEAR_H
#define WEAR_H
#include <iostream>
#include <string>
using string = std::string;
class Wear {
public:
    Wear();
    Wear(std::string id, std::string name);

    std::string getId() const;
    void setId(const std::string& id);

    std::string getName() const;
    void setName(const std::string& name);
    bool operator == (const Wear& rhs) const;

private:
    std::string id;
    std::string name;
};

#endif

