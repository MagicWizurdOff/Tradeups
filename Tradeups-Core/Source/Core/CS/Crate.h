#pragma once
#ifndef CREATE_H
#define CREATE_H
#include <iostream>
#include <string>
using string = std::string;
class Crate {
public:
    Crate();
    Crate(std::string id, std::string name, std::string image);

    std::string getId() const;
    void setId(const std::string& id);

    std::string getName() const;
    void setName(const std::string& name);

    std::string getImage() const;
    void setImage(const std::string& image);

    bool operator == (const Crate& rhs) const;

private:
    std::string id;
    std::string name;
    std::string image;
};

#endif

