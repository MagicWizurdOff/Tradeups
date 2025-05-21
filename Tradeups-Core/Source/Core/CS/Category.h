#pragma once
#ifndef CATEGORY_H
#define CATEGORY_H
#include <iostream>
#include <string>
using string = std::string;
class Category {
public:
    Category();
    Category(std::string id, std::string name);

    std::string getId() const;
    void setId(const std::string& id);

    std::string getName() const;
    void setName(const std::string& name);

    bool operator == (const Category& rhs) const;

private:
    std::string id;
    std::string name;
};
#endif
