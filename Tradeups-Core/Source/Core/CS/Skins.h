#ifndef SKINS_H
#define SKINS_H
#include <iostream>
#include <vector>
#include <fstream> 
#include <variant>
#include <array>
#include <nlohmann/json.hpp>

#include "Skin.h"
#include "Category.h"
#include "Collection.h"
#include "Crate.h"
#include "Pattern.h"-
#include "Rarity.h"
#include "Team.h"
#include "Weapon.h"
#include "Wear.h"
#include "../TradeUps/TradeUp.h"

#include "FilterType.h"


class Skins {
public:
    std::vector<Skin> skins;
    Skins(std::string fileName);
    static void logSkin(Skin skin);
   
    TradeUp getTradeUpSkinArrayFromId(const std::string& tradeUpId) {
        std::vector<TradeUpSkin> tradeUpSkins;
        std::array<TradeUpSkin, 10> tradeUpSkinsArray{};
        std::istringstream ss(tradeUpId);
        std::string token;

        while (std::getline(ss, token, ';')) {
            if (token.empty()) continue;

            std::istringstream pairStream(token);
            std::string idStr, floatStr;

            if (std::getline(pairStream, idStr, ':') && std::getline(pairStream, floatStr)) {
                std::string id = idStr;
                float f = std::stof(floatStr);
                tradeUpSkins.push_back(TradeUpSkin(this->id(id).getFirst(), f));
            }
        }

        if (tradeUpSkins.size() != 10) {
            throw std::runtime_error("TradeUp ID is invalid: expected 10 skins");
        }

        std::copy(tradeUpSkins.begin(), tradeUpSkins.end(), tradeUpSkinsArray.begin());
        TradeUp tradeUp(tradeUpSkinsArray, *this);
        return tradeUp;
    }


    // Filtr pro ID
    Skins& id(const std::string& id) {
        idFilter = id;
        hasIdFilter = true;
        return *this;
    }

    // Filtr pro název
    Skins& name(const std::string& name) {
        nameFilter = name;
        hasNameFilter = true;
        return *this;
    }

    // Filtr pro popis
    Skins& description(const std::string& description) {
        descriptionFilter = description;
        hasDescriptionFilter = true;
        return *this;
    }

    // Filtr pro zbraò (weapon)
    Skins& weapon(const Weapon& weapon) {
        weaponFilter = weapon;
        hasWeaponFilter = true;
        return *this;
    }

    // Weapon id filter
    Skins& weaponId(const std::string& weaponId) {
        weaponIdFilter = weaponId;
        hasWeaponIdFilter = true;
        return *this;
    }

    // Weapon weapon_id filter
    Skins& weaponWeaponId(const int weaponWeaponId) {
        weaponWeaponIdFilter = weaponWeaponId;
        hasWeaponWeaponIdFilter = true;
        return *this;
    }

    // Weapon name filter
    Skins& weaponName(const std::string weaponName) {
        weaponNameFilter = weaponName;
        hasWeaponNameFilter = true;
        return *this;
    }

    // Filtr pro kategorii (category)
    Skins& category(const Category& category) {
        categoryFilter = category;
        hasCategoryFilter = true;
        return *this;
    }

    // Filtr pro id kategorie (category)
    Skins& categoryId(const std::string& categoryId) {
        categoryIdFilter = categoryId;
        hasCategoryIdFilter = true;
        return *this;
    }

    // Filtr pro name kategorie (category)
    Skins& categoryName(const std::string& categoryName) {
        categoryNameFilter = categoryName;
        hasCategoryNameFilter = true;
        return *this;
    }

    // Filtr pro pattern (category)
    Skins& pattern(const Pattern& pattern) {
        patternFilter = pattern;
        hasPatternFilter = true;
        return *this;
    }

    // Filtr pro pattern (category)
    Skins& patternId(const std::string& pattern) {
        patternIdFilter = pattern;
        hasPatternIdFilter = true;
        return *this;
    }

    // Filtr pro pattern (category)
    Skins& patternName(const std::string& pattern) {
        patternNameFilter = pattern;
        hasPatternNameFilter = true;
        return *this;
    }

    // Filtr pro min_float a max_float
    Skins& minFloat(float minFloat) {
        minFloatFilter = minFloat;
        hasMinFloatFilter = true;
        return *this;
    }

    // Filtr pro min_float a max_float
    Skins& maxFloat(float maxFloat) {
        maxFloatFilter = maxFloat;
        hasMaxFloatFilter = true;
        return *this;
    }

    // Filtr pro min_float a max_float
    Skins& floatRange(float minFloat, float maxFloat) {
        minFloatFilter = minFloat;
        maxFloatFilter = maxFloat;
        return *this;
    }

    // Filtr pro rarity
    Skins& rarity(const Rarity& rarity) {
        rarityFilter = rarity;
        hasRarityFilter = true;
        return *this;
    }

    // Filtr pro rarity
    Skins& rarityId(const std::string& rarity) {
        rarityIdFilter = rarity;
        hasRarityIdFilter = true;
        return *this;
    }

    // Filtr pro rarity
    Skins& rarityName(const std::string& rarity) {
        rarityNameFilter = rarity;
        hasRarityIdFilter = true;
        return *this;
    }

    // Filtr pro rarity
    Skins& rarityColor(const std::string& rarity) {
        rarityColorFilter = rarity;
        hasRarityColorFilter = true;
        return *this;
    }

    // Filtr pro stattrack
    Skins& stattrack(bool stattrack) {
        stattrackFilter = stattrack;
        hasStattrackFilter = true;
        return *this;
    }

    // Filtr pro souvenir
    Skins& souvenier(bool souvenier) {
        souvenierFilter = souvenier;
        hasSouvenierFilter = true;
        return *this;
    }

    // Filtr pro legacy model
    Skins& legacyModel(bool legacyModel) {
        legacyModelFilter = legacyModel;
        hasLegacyModelFilter = true;
        return *this;
    }

    // Filtr pro paint index
    Skins& paintIndex(const std::string& paintIndex) {
        paintIndexFilter = paintIndex;
        hasPaintIndexFilter = true;
        return *this;
    }

    // Filtr pro wears
    Skins& wears(const std::vector<Wear>& wears) {
        wearsFilter = wears;
        hasWearsFilter = true;
        return *this;
    }

    // Filtr pro wears
    Skins& wear(const Wear& wears) {
        wearFilter = wears;
        hasWearFilter = true;
        return *this;
    }

    // Filtr pro wears
    Skins& wearId(const std::string& wears) {
        wearIdFilter = wears;
        hasWearIdFilter = true;
        return *this;
    }

    // Filtr pro wears
    Skins& wearName(const std::string& wears) {
        wearNameFilter = wears;
        hasWearNameFilter = true;
        return *this;
    }

    // Filtr pro collections
    Skins& collections(const std::vector<Collection>& collections) {
        collectionsFilter = collections;
        hasCollectionsFilter = true;
        return *this;
    }

    // Filtr pro collections
    Skins& collection(const Collection& collections) {
        collectionFilter = collections;
        hasCollectionFilter = true;
        return *this;
    }

    // Filtr pro collections
    Skins& collectionId(const std::string& collections) {
        collectionIdFilter = collections;
        collectionIdFilter = true;
        return *this;
    }

    // Filtr pro collections
    Skins& collectionName(const std::string& collections) {
        collectionNameFilter = collections;
        hasCollectionNameFilter = true;
        return *this;
    }

    // Filtr pro collections
    Skins& collectionImage(const std::string& collections) {
        collectionImageFilter = collections;
        collectionImageFilter = true;
        return *this;
    }



    // Filtr pro creates
    Skins& creates(const std::vector<Crate>& creates) {
        createsFilter = creates;
        hasCreatesFilter = true;
        return *this;
    }

    // Filtr pro creates
    Skins& create(const Crate& creates) {
        createFilter = creates;
        hasCreateFilter = true;
        return *this;
    }

    // Filtr pro creates
    Skins& createId(const std::string& creates) {
        createIdFilter = creates;
        hasCreateIdFilter = true;
        return *this;
    }

    // Filtr pro creates
    Skins& createName(const std::string& creates) {
        createNameFilter = creates;
        hasCreateNameFilter = true;
        return *this;
    }

    // Filtr pro creates
    Skins& createImage(const std::string& creates) {
        createImageFilter = creates;
        hasCreateImageFilter = true;
        return *this;
    }

    // Filtr pro team
    Skins& team(const Team& team) {
        teamFilter = team;
        hasTeamFilter = true;
        return *this;
    }

    // Filtr pro team
    Skins& teamId(const std::string& team) {
        teamIdFilter = team;
        hasTeamIdFilter = true;
        return *this;
    }

    // Filtr pro team
    Skins& teamName(const std::string& team) {
        teamNameFilter = team;
        hasTeamNameFilter = true;
        return *this;
    }


    bool arrContains(const std::array<FilterType, 14>& arr, const FilterType& value) {
        return std::find(arr.begin(), arr.end(), value) != arr.end();
    }

    std::vector<Skin> contains(FilterType filter, std::string text) {
        std::array<FilterType, 14> forbiddenTypes = {
            FilterType::Category,
            FilterType::Weapon,
            FilterType::WeaponWeaponId,
            FilterType::Pattern,
            FilterType::MinFloat,
            FilterType::MaxFloat,
            FilterType::Rarity,
            FilterType::Stattrack,
            FilterType::Souvenier,
            FilterType::LegacyModel,
            FilterType::Wears,
            FilterType::Collections,
            FilterType::Creates,
            FilterType::Team
        };

        std::vector<Skin> result = {};
        if (arrContains(forbiddenTypes, filter)) {
            return result;
        }
       
        for (const Skin& skin : skins) {
            if (!compareContains(filter, text, skin))
                result.push_back(skin);
            }
        reset();
        return result;
    }

    bool compareContains(FilterType filter, std::string text, Skin skin) const {
        bool match = true;

        if (!skin.getId().empty() && skin.getId().find(text) != std::string::npos && filter == FilterType::Id) match = false;
        if (!skin.getName().empty() && skin.getName().find(text) != std::string::npos && filter == FilterType::Name) match = false;
        if (!skin.getDescription().empty() && skin.getDescription().find(text) != std::string::npos && filter == FilterType::Description) match = false;

        if (!skin.getWeapon().getId().empty() && skin.getWeapon().getId().find(text) != std::string::npos && filter == FilterType::Weapon) match = false;
        if (!skin.getWeapon().getName().empty() && skin.getWeapon().getName().find(text) != std::string::npos && filter == FilterType::WeaponName) match = false;

        if (!skin.getCategory().getId().empty() && skin.getCategory().getId().find(text) != std::string::npos && filter == FilterType::Category) match = false;
        if (!skin.getCategory().getName().empty() && skin.getCategory().getName().find(text) != std::string::npos && filter == FilterType::CategoryName) match = false;

        if (!skin.getPattern().getId().empty() && skin.getPattern().getId().find(text) != std::string::npos && filter == FilterType::Pattern) match = false;
        if (!skin.getPattern().getName().empty() && skin.getPattern().getName().find(text) != std::string::npos && filter == FilterType::PatternName) match = false;

        if (!skin.getRarity().getId().empty() && skin.getRarity().getId().find(text) != std::string::npos && filter == FilterType::Rarity) match = false;
        if (!skin.getRarity().getName().empty() && skin.getRarity().getName().find(text) != std::string::npos && filter == FilterType::RarityName) match = false;
        if (!skin.getRarity().getColor().empty() && skin.getRarity().getColor().find(text) != std::string::npos && filter == FilterType::RarityColor) match = false;

        if (!skin.getPaintIndex().empty() && skin.getPaintIndex().find(text) != std::string::npos && filter == FilterType::PaintIndex) match = false;

        for (Wear wear : skin.getWears()) {
            if (!wear.getId().empty() && wear.getId().find(text) != std::string::npos && filter == FilterType::WearId) match = false;
            if (!wear.getName().empty() && wear.getName().find(text) != std::string::npos && filter == FilterType::WearName) match = false;
        }

        for (Collection collection : skin.getCollections()) {
            if (!collection.getId().empty() && collection.getId().find(text) != std::string::npos && filter == FilterType::CollectionId) match = false;
            if (!collection.getName().empty() && collection.getName().find(text) != std::string::npos && filter == FilterType::CollectionName) match = false;
            if (!collection.getImage().empty() && collection.getImage().find(text) != std::string::npos && filter == FilterType::CollectionImage) match = false;
        }

        for (Crate create : skin.getCreates()) {
            if (!create.getId().empty() && create.getId().find(text) != std::string::npos && filter == FilterType::CreateId) match = false;
            if (!create.getName().empty() && create.getName().find(text) != std::string::npos && filter == FilterType::CreateName) match = false;
            if (!create.getImage().empty() && create.getImage().find(text) != std::string::npos && filter == FilterType::CreateImage) match = false;
        }

        if (!skin.getTeam().getId().empty() && skin.getTeam().getId().find(text) != std::string::npos && filter == FilterType::TeamId) match = false;
        if (!skin.getTeam().getName().empty() && skin.getTeam().getName().find(text) != std::string::npos && filter == FilterType::TeamName) match = false;

        return match;
    }

    bool compare(Skin skin) const {

        bool match = true;
        if (hasIdFilter && !skin.getId().empty() && skin.getId() != idFilter) match = false;
        if (hasNameFilter && !skin.getName().empty() && skin.getName() != nameFilter) match = false;
        if (hasDescriptionFilter && !skin.getDescription().empty() && skin.getDescription() != descriptionFilter) match = false;

        if (hasWeaponFilter && !skin.getWeapon().getId().empty() && skin.getWeapon() != weaponFilter) match = false;
        if (hasWeaponIdFilter && !skin.getWeapon().getId().empty() && skin.getWeapon().getId() != weaponIdFilter) match = false;
        if (hasWeaponWeaponIdFilter && skin.getWeapon().getWeaponId() != weaponWeaponIdFilter) match = false;
        if (hasWeaponNameFilter && !skin.getWeapon().getName().empty() && skin.getWeapon().getName() != weaponNameFilter) match = false;

        if (hasCategoryFilter && !skin.getCategory().getId().empty() && skin.getCategory() != categoryFilter) match = false;
        if (hasCategoryIdFilter && !skin.getCategory().getId().empty() && skin.getCategory().getId() != categoryIdFilter) match = false;
        if (hasCategoryNameFilter && !skin.getCategory().getName().empty() && skin.getCategory().getName() != categoryNameFilter) match = false;

        if (hasPatternFilter && !skin.getPattern().getId().empty() && skin.getPattern() != patternFilter) match = false;
        if (hasPatternIdFilter && !skin.getPattern().getId().empty() && skin.getPattern().getId() != patternIdFilter) match = false;
        if (hasPatternNameFilter && !skin.getPattern().getName().empty() && skin.getPattern().getName() != patternNameFilter) match = false;

        if (hasMinFloatFilter && skin.getMinFloat() != minFloatFilter) match = false;
        if (hasMaxFloatFilter && skin.getMaxFloat() != maxFloatFilter) match = false;

        if (hasRarityFilter && !skin.getRarity().getId().empty() && skin.getRarity() != rarityFilter) match = false;
        if (hasRarityIdFilter && !skin.getRarity().getId().empty() && skin.getRarity().getId() != rarityIdFilter) match = false;
        if (hasRarityNameFilter && !skin.getRarity().getName().empty() && skin.getRarity().getName() != rarityNameFilter) match = false;
        if (hasRarityColorFilter && !skin.getRarity().getColor().empty() && skin.getRarity().getColor() != rarityColorFilter) match = false;

        if (hasStattrackFilter && !skin.hasStattrack() && skin.hasStattrack() != stattrackFilter) match = false;
        if (hasSouvenierFilter && !skin.isSouvenier() && skin.isSouvenier() != souvenierFilter) match = false;
        if (hasLegacyModelFilter && !skin.hasLegacyModel() && skin.hasLegacyModel() != legacyModelFilter) match = false;

        if (hasPaintIndexFilter && !skin.getPaintIndex().empty() && skin.getPaintIndex() != paintIndexFilter) match = false;

        if (hasWearsFilter && !skin.getWears().empty() && skin.getWears() != wearsFilter) match = false;
        for (const Wear& wear : skin.getWears()) {
            if (hasWearFilter && !wear.getId().empty() && wear != wearFilter) match = false;
            if (hasWearIdFilter && !wear.getId().empty() && wear.getId() != wearIdFilter) match = false;
            if (hasWearNameFilter && !wear.getName().empty() && wear.getName() != wearNameFilter) match = false;
        }

        if (hasCollectionsFilter && !skin.getCollections().empty() && skin.getCollections() != collectionsFilter) match = false;
        for (const Collection& collection : skin.getCollections()) {
            if (hasCollectionFilter && !collection.getId().empty() && collection != collectionFilter) match = false;
            if (hasCollectionIdFilter && !collection.getId().empty() && collection.getId() != collectionIdFilter) match = false;
            if (hasCollectionNameFilter && !collection.getName().empty() && collection.getName() != collectionNameFilter) match = false;
            if (hasCollectionImageFilter && !collection.getImage().empty() && collection.getImage() != collectionImageFilter) match = false;
        }

        if (hasCreatesFilter && !skin.getCreates().empty() && skin.getCreates() != createsFilter) match = false;
        for (const Crate& create : skin.getCreates()) {
            if (hasCreateFilter && !create.getId().empty() && create != createFilter) match = false;
            if (hasCreateIdFilter && !create.getId().empty() && create.getId() != createIdFilter) match = false;
            if (hasCreateNameFilter && !create.getName().empty() && create.getName() != createNameFilter) match = false;
            if (hasCreateImageFilter && !create.getImage().empty() && create.getImage() != createImageFilter) match = false;
        }

        if (hasTeamFilter && !skin.getTeam().getId().empty() && skin.getTeam() != teamFilter) match = false;
        if (hasTeamIdFilter && !skin.getTeam().getId().empty() && skin.getTeam().getId() != teamIdFilter) match = false;
        if (hasTeamNameFilter && !skin.getTeam().getName().empty() && skin.getTeam().getName() != teamNameFilter) match = false;
        return match;

    }
    void reset() {
        idFilter = "";
        nameFilter = "";
        descriptionFilter = "";

        weaponFilter = Weapon();
        weaponIdFilter = "";
        weaponWeaponIdFilter = 0;
        weaponNameFilter = "";

        categoryFilter = Category();
        categoryIdFilter = "";
        categoryNameFilter = "";

        patternFilter = Pattern();
        patternIdFilter = "";
        patternNameFilter = "";

        minFloatFilter = -1.0f;
        maxFloatFilter = -1.0f;

        rarityFilter = Rarity();
        rarityIdFilter = "";
        rarityNameFilter = "";
        rarityColorFilter = "";

        stattrackFilter = false;
        souvenierFilter = false;
        legacyModelFilter = false;

        paintIndexFilter = "";

        wearsFilter.clear();
        wearFilter = Wear();
        wearIdFilter = "";
        wearNameFilter = "";

        collectionsFilter.clear();
        collectionFilter = Collection();
        collectionIdFilter = "";
        collectionNameFilter = "";
        collectionImageFilter = "";

        createsFilter.clear();
        createFilter = Crate();
        createIdFilter = "";
        createNameFilter = "";
        createImageFilter = "";

        teamFilter = Team();
        teamIdFilter = "";
        teamNameFilter = "";

        hasIdFilter = false;
        hasNameFilter = false;
        hasDescriptionFilter = false;

        hasWeaponFilter = false;
        hasWeaponIdFilter = false;
        hasWeaponWeaponIdFilter = false;
        hasWeaponNameFilter = false;

        hasCategoryFilter = false;
        hasCategoryIdFilter = false;
        hasCategoryNameFilter = false;

        hasPatternFilter = false;
        hasPatternIdFilter = false;
        hasPatternNameFilter = false;

        hasMinFloatFilter = false;
        hasMaxFloatFilter = false;

        hasRarityFilter = false;
        hasRarityIdFilter = false;
        hasRarityNameFilter = false;
        hasRarityColorFilter = false;

        hasStattrackFilter = false;
        hasSouvenierFilter = false;
        hasLegacyModelFilter = false;

        hasPaintIndexFilter = false;

        hasWearsFilter = false;
        hasWearFilter = false;
        hasWearIdFilter = false;
        hasWearNameFilter = false;

        hasCollectionsFilter = false;
        hasCollectionFilter = false;
        hasCollectionIdFilter = false;
        hasCollectionNameFilter = false;
        hasCollectionImageFilter = false;

        hasCreatesFilter = false;
        hasCreateFilter = false;
        hasCreateIdFilter = false;
        hasCreateNameFilter = false;
        hasCreateImageFilter = false;

        hasTeamFilter = false;
        hasTeamIdFilter = false;
        hasTeamNameFilter = false;
    }

    using variants = std::variant<
        int,
        std::string,
        bool,
        Category,
        Collection,
        std::vector<Collection>,
        Crate,
        std::vector<Crate>,
        Pattern,
        Rarity,
        Team,
        Weapon,
        Wear,
        std::vector<Wear>,
        float,
        std::vector<std::string>
    >;

    std::vector<variants> pluck(FilterType filter) {
        for (const Skin& skin : skins) {
            std::vector<variants> result = {};

            if (compare(skin))
                
                switch (filter) {
                case FilterType::Name:
                    result.push_back(skin.getName());
                    break;

                case FilterType::Description:
                    result.push_back(skin.getDescription());
                    break;

                case FilterType::Weapon:
                    result.push_back(skin.getWeapon());
                    break;

                case FilterType::WeaponId:
                    result.push_back(skin.getWeapon().getId());
                    break;

                case FilterType::WeaponWeaponId:
                    result.push_back(skin.getWeapon().getWeaponId());
                    break;

                case FilterType::WeaponName:
                    result.push_back(skin.getWeapon().getName());
                    break;

                case FilterType::Category:
                    result.push_back(skin.getCategory());
                    break;

                case FilterType::CategoryId:
                    result.push_back(skin.getCategory().getId());
                    break;

                case FilterType::CategoryName:
                    result.push_back(skin.getCategory().getName());
                    break;

                case FilterType::Pattern:
                    result.push_back(skin.getPattern());
                    break;

                case FilterType::PatternId:
                    result.push_back(skin.getPattern().getId());
                    break;

                case FilterType::PatternName:
                    result.push_back(skin.getPattern().getName());
                    break;

                case FilterType::MinFloat:
                    result.push_back(skin.getMinFloat());
                    break;

                case FilterType::MaxFloat:
                    result.push_back(skin.getMaxFloat());
                    break;

                case FilterType::Rarity:
                    result.push_back(skin.getRarity());
                    break;

                case FilterType::RarityId:
                    result.push_back(skin.getRarity().getId());
                    break;

                case FilterType::RarityName:
                    result.push_back(skin.getRarity().getName());
                    break;

                case FilterType::RarityColor:
                    result.push_back(skin.getRarity().getColor());
                    break;

                case FilterType::Stattrack:
                    result.push_back(skin.hasStattrack());
                    break;

                case FilterType::Souvenier:
                    result.push_back(skin.isSouvenier());
                    break;

                case FilterType::LegacyModel:
                    result.push_back(skin.hasLegacyModel());
                    break;

                case FilterType::PaintIndex:
                    result.push_back(skin.getPaintIndex());
                    break;

                case FilterType::Wears:
                    result.push_back(skin.getWears());
                    break;
                case FilterType::WearId: {
                    std::vector<std::string> wearIds = {};
                    for (Wear wear : skin.getWears()) {
                        wearIds.push_back(wear.getId());
                    }
                    result.push_back(wearIds);
                    break;
                }

                case FilterType::WearName: {
                    std::vector<std::string> wearNames = {};
                    for (Wear wear : skin.getWears()) {
                        wearNames.push_back(wear.getName());
                    }
                    result.push_back(wearNames);
                    break;
                }

                case FilterType::Collections:
                    result.push_back(skin.getCollections());
                    break;

                case FilterType::CollectionId: {
                    std::vector<std::string> collectionIds = {};
                    for (Collection collection : skin.getCollections()) {
                        collectionIds.push_back(collection.getName());
                    }
                    result.push_back(collectionIds);
                    break;
                }
                case FilterType::CollectionName: {
                    std::vector<std::string> collectionNames = {};
                    for (Collection collection : skin.getCollections()) {
                        collectionNames.push_back(collection.getName());
                    }
                    result.push_back(collectionNames);
                    break;
                }
                case FilterType::CollectionImage: {
                    std::vector<std::string> collectionImages = {};
                    for (Collection collection : skin.getCollections()) {
                        collectionImages.push_back(collection.getName());
                    }
                    result.push_back(collectionImages);
                    break;
                }
                case FilterType::Creates:
                    result.push_back(skin.getCreates());
                    break;

                case FilterType::CreateId: {
                    std::vector<std::string> createIds = {};
                    for (Crate create : skin.getCreates()) {
                        createIds.push_back(create.getName());
                    }
                    result.push_back(createIds);
                    break;
                }
                case FilterType::CreateName: {
                    std::vector<std::string> createNames = {};
                    for (Crate create : skin.getCreates()) {
                        createNames.push_back(create.getName());
                    }
                    result.push_back(createNames);
                    break;
                }
                case FilterType::CreateImage: {
                    std::vector<std::string> createImages = {};
                    for (Crate create : skin.getCreates()) {
                        createImages.push_back(create.getName());
                    }
                    result.push_back(createImages);
                    break;
                }
                case FilterType::Team:
                    result.push_back(skin.getTeam());
                    break;

                case FilterType::TeamId:
                    result.push_back(skin.getTeam().getId());
                    break;

                case FilterType::TeamName:
                    result.push_back(skin.getTeam().getName());
                    break;
                }
                reset();
            return result;
        }
    }

    Skin getFirst() {
        for (const Skin& skin : skins) {
            if (compare(skin)) {
                reset();
                return skin;
            }
        }
        reset();
    }

    std::vector<Skin> where(FilterType filter, std::string search) {
        std::vector<Skin> result;
        for (Skin skin : skins) {

            switch (filter) {
            case FilterType::Id:
                if (skin.getId() == search)
                    result.push_back(skin);
                break;
            case FilterType::Name:
                if (skin.getName() == search)
                    result.push_back(skin);
                break;
            case FilterType::Description:
                if (skin.getDescription() == search)
                    result.push_back(skin);
                break;
            case FilterType::WeaponId:
                if (skin.getWeapon().getId() == search)
                    result.push_back(skin);
                break;
            case FilterType::WeaponWeaponId:
                if (!std::stoi(search))
                    break;
                if (skin.getWeapon().getWeaponId() == std::stoi(search));
                    result.push_back(skin);
                break;
            case FilterType::WeaponName:
                if (skin.getWeapon().getName() == search)
                    result.push_back(skin);
                break;
            case FilterType::CategoryId:
                if (skin.getCategory().getId() == search)
                    result.push_back(skin);
                break;
            case FilterType::CategoryName:
                if (skin.getCategory().getName() == search)
                    result.push_back(skin);
                break;
            case FilterType::PatternId:
                if (skin.getPattern().getId() == search)
                    result.push_back(skin);
                break;
            case FilterType::PatternName:
                if (skin.getPattern().getName() == search)
                    result.push_back(skin);
                break;
            case FilterType::MinFloat:
                if (skin.getMinFloat() == std::stof(search))
                    result.push_back(skin);
                break;
            case FilterType::MaxFloat:
                if (skin.getMaxFloat() == std::stof(search))
                    result.push_back(skin);
                break;
            case FilterType::RarityId:
                if (skin.getRarity().getId() == search)
                    result.push_back(skin);
                break;
            case FilterType::RarityName:
                if (skin.getRarity().getName() == search)
                    result.push_back(skin);
                break;
            case FilterType::RarityColor:
                if (skin.getRarity().getColor() == search)
                    result.push_back(skin);
                break;
            case FilterType::Stattrack:
                if (skin.hasStattrack() == (search == "true"))
                    result.push_back(skin);
                break;
            case FilterType::Souvenier:
                if (skin.isSouvenier() == (search == "true"))
                    result.push_back(skin);
                break;
            case FilterType::LegacyModel:
                if (skin.hasLegacyModel() == (search == "true"))
                    result.push_back(skin);
                break;
            case FilterType::PaintIndex:
                if (skin.getPaintIndex() == search)
                    result.push_back(skin);
                break;
            case FilterType::WearId:
                for (const Wear& wear : skin.getWears())
                    if (wear.getId() == search)
                        result.push_back(skin);
                break;
            case FilterType::WearName:
                for (const Wear& wear : skin.getWears())
                    if (wear.getName() == search)
                        result.push_back(skin);
                break;
            case FilterType::CollectionId:
                for (const Collection& collection : skin.getCollections())
                    if (collection.getId() == search)
                        result.push_back(skin);
                break;
            case FilterType::CollectionName:
                for (const Collection& collection : skin.getCollections())
                    if (collection.getName() == search)
                        result.push_back(skin);
                break;
            case FilterType::CollectionImage:
                for (const Collection& collection : skin.getCollections())
                    if (collection.getImage() == search)
                        result.push_back(skin);
                break;
            case FilterType::CreateId:
                for (const Crate& create : skin.getCreates())
                    if (create.getId() == search)
                        result.push_back(skin);
                break;
            case FilterType::CreateName:
                for (const Crate& create : skin.getCreates())
                    if (create.getName() == search)
                        result.push_back(skin);
                break;
            case FilterType::CreateImage:
                for (const Crate& create : skin.getCreates())
                    if (create.getImage() == search)
                        result.push_back(skin);
                break;
            case FilterType::TeamId:
                if (skin.getTeam().getId() == search)
                    result.push_back(skin);
                break;
            case FilterType::TeamName:
                if (skin.getTeam().getName() == search)
                    result.push_back(skin);
                break;
            case FilterType::Unknown:
            default:
                break;
            }

        }
        return result;
    }

    // Metoda pro získání výsledkù
    std::vector<Skin> get() {
        std::vector<Skin> result;

        for (const Skin& skin : skins) {
            if (compare(skin))
                result.push_back(skin);
        }
        reset();
        return result;
    }

private:
    void loadSkins(std::string file);
    
    std::string idFilter,
         nameFilter,
         descriptionFilter;

    Weapon weaponFilter;
    std::string weaponIdFilter;
    int weaponWeaponIdFilter;
    std::string weaponNameFilter;

    Category categoryFilter;
    std::string categoryIdFilter,
        categoryNameFilter;

    Pattern patternFilter;
    std::string patternIdFilter,
        patternNameFilter;

    float minFloatFilter = -1.0f, 
        maxFloatFilter = -1.0f;

    Rarity rarityFilter;
    std::string rarityIdFilter,
         rarityNameFilter,
         rarityColorFilter;

    bool stattrackFilter = false, 
        souvenierFilter = false, 
        legacyModelFilter = false;

    std::string paintIndexFilter;

    std::vector<Wear> wearsFilter;
    Wear wearFilter;
    std::string wearIdFilter,
        wearNameFilter;

    std::vector<Collection> collectionsFilter;
    Collection collectionFilter;
    std::string collectionIdFilter,
        collectionNameFilter,
        collectionImageFilter;

    std::vector<Crate> createsFilter;
    Crate createFilter;
    std::string createIdFilter,
        createNameFilter,
        createImageFilter;

    Team teamFilter;
    std::string teamIdFilter,
        teamNameFilter;

    bool hasIdFilter = false,
        hasNameFilter = false,
        hasDescriptionFilter = false,

        hasWeaponFilter = false,
        hasWeaponIdFilter = false,
        hasWeaponWeaponIdFilter = false,
        hasWeaponNameFilter = false,

        hasCategoryFilter = false,
        hasCategoryIdFilter = false,
        hasCategoryNameFilter = false,

        hasPatternFilter = false,
        hasPatternIdFilter = false,
        hasPatternNameFilter = false,

        hasMinFloatFilter = false,
        hasMaxFloatFilter = false,

        hasRarityFilter = false,
        hasRarityIdFilter = false,
        hasRarityNameFilter = false,
        hasRarityColorFilter = false,

        hasStattrackFilter = false,
        hasSouvenierFilter = false,
        hasLegacyModelFilter = false,

        hasPaintIndexFilter = false,

        hasWearsFilter = false,
        hasWearFilter = false,
        hasWearIdFilter = false,
        hasWearNameFilter = false,

        hasCollectionsFilter = false,
        hasCollectionFilter = false,
        hasCollectionIdFilter = false,
        hasCollectionNameFilter = false,
        hasCollectionImageFilter = false,

        hasCreatesFilter = false,
        hasCreateFilter = false,
        hasCreateIdFilter = false,
        hasCreateNameFilter = false,
        hasCreateImageFilter = false,

        hasTeamFilter = false,
        hasTeamIdFilter = false,
        hasTeamNameFilter = false;



};

#endif // !SKINS_H