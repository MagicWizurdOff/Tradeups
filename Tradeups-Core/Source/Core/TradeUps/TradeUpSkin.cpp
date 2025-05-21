#include "TradeUpSkin.h"
using json = nlohmann::json;

TradeUpSkin::TradeUpSkin() : skin(Skin()), skin_float(-1.0f) {
	this->skin = skin;
	this->skin_float = skin_float;
	this->wear = convertFloatToWear();
	this->skinName = skin.getName() + " " + this->wear;
	fetchMarketPrice();
}


TradeUpSkin::TradeUpSkin(Skin skin, float skin_float) : skin(Skin()), skin_float(-1.0f) {
	this->skin = skin;
	this->skin_float = skin_float;
	this->wear = convertFloatToWear();
	this->skinName = skin.getName() + " " + this->wear;
	fetchMarketPrice();
}

Skin TradeUpSkin::getSkin() const {
	return this->skin;
}
float TradeUpSkin::getSkinFloat() const {
	return this->skin_float;
}
float TradeUpSkin::getPrice() const {
	return this->price;
}
int TradeUpSkin::getVolume() const {
	return this->volume;
}
std::string TradeUpSkin::getWear() const {
	return this->wear;
}
std::string TradeUpSkin::getSkinName() const {
	return this->skinName;
}


std::string TradeUpSkin::convertFloatToWear() const {
	if (skin_float > 0 && skin_float <= 0.07)
		return "(Factory New)";
	if (skin_float > 0.07 && skin_float <= 0.15)
		return "(Minimal Wear)";
	if (skin_float > 0.15 && skin_float <= 0.38)
		return "(Field-Tested)";
	if (skin_float > 0.38 && skin_float <= 0.45)
		return "(Well-Worn)";
	if (skin_float > 0.45 && skin_float <= 0.1)
		return "(Battle-Scarred)";
}

void TradeUpSkin::fetchMarketPrice()
{
	
	try {
		std::string priceStringJson = SteamAPI::getSteamMarketPrice(this->skinName);
		json priceData = json::parse(priceStringJson);
		std::string floatPriceString;
		if (priceData.contains("volume")) {
			std::cout << "Has volume!" << std::endl;
			std::string volume = priceData["volume"];
			this->volume = std::stoi(volume);
		}

		if (priceData.contains("lowest_price"))
			floatPriceString = priceData["lowest_price"];
		else if (priceData.contains("median_price"))
			floatPriceString = priceData["median_price"];
		else
			return;
		try {
			price = std::stof(floatPriceString);
		}
		catch (const std::exception& e) {
			std::cerr << "Chyba pøi konverzi: " << e.what() << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error fetching Market Price: " << e.what() << std::endl;
	}
	catch (const nlohmann::json::exception& e) {
		std::cerr << "JSON error: " << e.what() << std::endl;
	}
	
}

