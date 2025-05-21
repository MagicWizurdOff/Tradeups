#pragma once
#ifndef PATTERN_H
#define PATTERN_H
#include <iostream>
#include <string>
using string = std::string;
class Pattern {
public:
    Pattern();
    Pattern(std::string id, std::string name);

    std::string getId() const;
    void setId(const std::string& id);

    std::string getName() const;
    void setName(const std::string& name);

    bool operator == (const Pattern& rhs) const;

private:
    std::string id;
    std::string name;
};

#endif

