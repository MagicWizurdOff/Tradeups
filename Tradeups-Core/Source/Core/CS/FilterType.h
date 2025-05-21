#pragma once
enum class FilterType {
    Id,
    Name,
    Description,

    Weapon,
    WeaponId,
    WeaponWeaponId,
    WeaponName,

    Category,
    CategoryId,
    CategoryName,

    Pattern,
    PatternId,
    PatternName,

    MinFloat,
    MaxFloat,

    Rarity,
    RarityId,
    RarityName,
    RarityColor,

    Stattrack,
    Souvenier,
    LegacyModel,

    PaintIndex,

    Wears,
    WearId,
    WearName,

    Collections,
    CollectionId,
    CollectionName,
    CollectionImage,

    Creates,
    CreateId,
    CreateName,
    CreateImage,

    Team,
    TeamId,
    TeamName,

    Unknown
};

inline FilterType getFilterType(const std::string& str) {
    static const std::unordered_map<std::string, FilterType> strToEnumMap = {
        {"Id", FilterType::Id},
        {"Name", FilterType::Name},
        {"Description", FilterType::Description},
        {"Weapon", FilterType::Weapon},
        {"WeaponId", FilterType::WeaponId},
        {"WeaponWeaponId", FilterType::WeaponWeaponId},
        {"WeaponName", FilterType::WeaponName},
        {"Category", FilterType::Category},
        {"CategoryId", FilterType::CategoryId},
        {"CategoryName", FilterType::CategoryName},
        {"Pattern", FilterType::Pattern},
        {"PatternId", FilterType::PatternId},
        {"PatternName", FilterType::PatternName},
        {"MinFloat", FilterType::MinFloat},
        {"MaxFloat", FilterType::MaxFloat},
        {"Rarity", FilterType::Rarity},
        {"RarityId", FilterType::RarityId},
        {"RarityName", FilterType::RarityName},
        {"RarityColor", FilterType::RarityColor},
        {"Stattrack", FilterType::Stattrack},
        {"Souvenier", FilterType::Souvenier},
        {"LegacyModel", FilterType::LegacyModel},
        {"PaintIndex", FilterType::PaintIndex},
        {"Wears", FilterType::Wears},
        {"WearId", FilterType::WearId},
        {"WearName", FilterType::WearName},
        {"Collections", FilterType::Collections},
        {"CollectionId", FilterType::CollectionId},
        {"CollectionName", FilterType::CollectionName},
        {"CollectionImage", FilterType::CollectionImage},
        {"Creates", FilterType::Creates},
        {"CreateId", FilterType::CreateId},
        {"CreateName", FilterType::CreateName},
        {"CreateImage", FilterType::CreateImage},
        {"Team", FilterType::Team},
        {"TeamId", FilterType::TeamId},
        {"TeamName", FilterType::TeamName}
    };

    auto it = strToEnumMap.find(str);
    return (it != strToEnumMap.end()) ? it->second : FilterType::Unknown;
}
