#pragma once
#ifndef SKIN_H
#define SKIN_H

#include <string>
#include <vector>
#include "Weapon.h"
#include "Category.h" 
#include "Pattern.h"
#include "Rarity.h" 
#include "Wear.h"
#include "Collection.h" 
#include "Crate.h" 
#include "Team.h"

class Skin {
public:

    bool operator == (const Skin& rhs) const;

    Skin(std::string id, std::string name, std::string description, Weapon weapon, Category category, Pattern pattern,
        float min_float, float max_float, Rarity rarity, bool stattrack, bool souvenier, std::string paint_index,
        std::vector<Wear> wears, std::vector<Collection> collections, std::vector<Crate> creates, Team team,
        bool legacy_model, std::string image);

    Skin();

    std::string getId() const;
    std::string getName() const;
    std::string getDescription() const;
    Weapon getWeapon() const;
    Category getCategory() const;
    Pattern getPattern() const;
    float getMinFloat() const;
    float getMaxFloat() const;
    Rarity getRarity() const;
    bool hasStattrack() const;
    bool isSouvenier() const;
    std::string getPaintIndex() const;
    std::vector<Wear> getWears() const;
    std::vector<Collection> getCollections() const;
    std::vector<Crate> getCreates() const;
    Team getTeam() const;
    bool hasLegacyModel() const;
    std::string getImage() const;

 
    void setId(std::string id);
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setWeapon(const Weapon& weapon);
    void setCategory(const Category& category);
    void setPattern(const Pattern& pattern);
    void setMinFloat(float min_float);
    void setMaxFloat(float max_float);
    void setRarity(const Rarity& rarity);
    void setStattrack(bool stattrack);
    void setSouvenier(bool souvenier);
    void setPaintIndex(const std::string& paint_index);
    void setWears(const std::vector<Wear>& wears);
    void setCollections(const std::vector<Collection>& collections);
    void setCreates(const std::vector<Crate>& creates);
    void setTeam(const Team& team);
    void setLegacyModel(bool legacy_model);
    void setImage(const std::string& image);

private:
    std::string id;
    std::string name;
    std::string description;
    Weapon weapon;
    Category category;
    Pattern pattern;
    float min_float;
    float max_float;
    Rarity rarity;
    bool stattrack;
    bool souvenier;
    std::string paint_index;
    std::vector<Wear> wears;
    std::vector<Collection> collections;
    std::vector<Crate> creates;
    Team team;
    bool legacy_model;
    std::string image;
};

#endif 
