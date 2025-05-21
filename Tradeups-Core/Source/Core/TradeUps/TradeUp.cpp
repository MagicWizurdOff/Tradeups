#include "TradeUp.h"

TradeUp::TradeUp(std::array<TradeUpSkin, 10> skins, const Skins& allSkins) : skins(skins), allSkins(allSkins)
{
    this->allSkins = allSkins;
    this->id = createId();
    for (TradeUpSkin skin : skins) {
        if (skin.getSkin().isSouvenier()) {
            std::cout << "TradeUp id: " << id << " contains a souvenier inside of input skins. Aborting TradeUp!";
            return;
        }
        if (skin.getSkin().getCategory().getName() == "Knives") {
            std::cout << "TradeUp id: " << id << " contains a knife inside of input skins. Aborting TradeUp!";
            return;
        }
    }
    this->averageFloat = calculateAverageFloat();
    this->tradeUpInputRarity = getInputRarity();
}

RarityEnum TradeUp::getInputRarity() {
    RarityEnum rarity = RarityEnum::Unknown;
    for (TradeUpSkin skin : skins) {
        RarityEnum tradeUpSkinRarity = getRarityEnum(skin.getSkin().getRarity().getName());
        if (rarity != RarityEnum::Unknown && rarity != tradeUpSkinRarity) {
            std::cerr << "There is a skin with different rarity then the rest of the skins it this trade up: " << id << std::endl;
            return RarityEnum::Unknown;
        }
        rarity = tradeUpSkinRarity;
    }

    return rarity;
}


std::string TradeUp::createId() const 
{
    std::ostringstream oss;
    for (const auto& skin : skins) {
        oss << skin.getSkin().getId() << ":" << std::fixed << std::setprecision(5) << skin.getSkinFloat() << ";";
    }
    return oss.str();
}

float TradeUp::calculateAverageFloat() const
{
    float sumSkinFloats = 0.0f;
    for (TradeUpSkin skin : skins) {
        sumSkinFloats += skin.getSkinFloat();
    }
    float avgSkinFloat = sumSkinFloats / 10;

	return avgSkinFloat;
}

std::vector<TradeUpSkin> TradeUp::calculateOutComes()
{
    std::vector<TradeUpSkin> tradeUpOutcomes;
    std::map<std::string, Collection> inputCollections;
    for (TradeUpSkin skin : skins) {
        for (Collection collection : skin.getSkin().getCollections()) {
            if (!inputCollections.contains(collection.getName()))
                inputCollections[collection.getName()] = collection;
        }
    }
    RarityEnum rarity = RarityEnum::Unknown;
    for (const auto& pair : inputCollections) {
        std::vector<Skin> collectionOutcome = allSkins.collection(pair.second).get();
        for (Skin skin : collectionOutcome) {
            RarityEnum skinRarity = getRarityEnum(skin.getRarity().getName());
            if (rarity != RarityEnum::Unknown && rarity != skinRarity) {
                std::cout << "Some skin does not have the same rarity. Aborting!";
                return std::vector<TradeUpSkin>();
            }
        }
    }

    return tradeUpOutcomes;
}

float TradeUp::calculateProfitability() const
{

	return 0.0f;
}

float TradeUp::calculateProfit() const
{
	return 0.0f;
}

float TradeUp::oddsToProfit() const
{
	return 0.0f;
}

