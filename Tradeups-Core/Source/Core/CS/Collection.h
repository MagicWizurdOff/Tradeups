#pragma once
#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
#include <string>
using string = std::string;
class Collection {
public:
    Collection();
    Collection(std::string id, std::string name, std::string image);

    std::string getId() const;
    void setId(const std::string& id);

    std::string getName() const;
    void setName(const std::string& name);

    std::string getImage() const;
    void setImage(const std::string& image);

    bool operator == (const Collection& rhs) const;

private:
    std::string id;
    std::string name;
    std::string image;
};

#endif

