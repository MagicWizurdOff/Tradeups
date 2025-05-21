#pragma once
#ifndef RARITY_H
#define RARITY_H
#include <iostream>
#include <string>
using string = std::string;
enum RarityEnum {
    Unknown,
    Consumer,
    Industrial,
    Mil_Spec,
    Restricted,
    Classified,
    Covert,
    Contraband
};

static inline RarityEnum getRarityEnum(const std::string& str) {
    static const std::unordered_map<std::string, RarityEnum> strToEnumMap = {
        {"Consumer", RarityEnum::Consumer},
        {"Industrial", RarityEnum::Industrial},
        {"Mil_Spec", RarityEnum::Mil_Spec},
        {"Restricted", RarityEnum::Restricted},
        {"Classified", RarityEnum::Classified},
        {"Covert", RarityEnum::Covert},
        {"Contraband", RarityEnum::Contraband},
        {"Unknown", RarityEnum::Unknown}
    };
}
static inline int getRarityIndexInt(const RarityEnum searchedRarityEnum) {
    for (int i = 0; i < 8; i++)
        if ((RarityEnum)i == searchedRarityEnum)
            return i;

    return -1;
}

class Rarity {
public:
    Rarity();
    Rarity(std::string id, std::string name, std::string color);

    std::string getId() const;
    void setId(const std::string& id);

    std::string getName() const;
    void setName(const std::string& name);

    std::string getColor() const;
    void setColor(const std::string& color);

    bool operator == (const Rarity& rhs) const;

private:
    std::string id;
    std::string name;
    std::string color;
};
#endif
