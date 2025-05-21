#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include "../CS/Skin.h"
#include "SteamAPI.h"
#include "../CS/Skins.h"

class TradeUpSkin {
public:

	TradeUpSkin();
	TradeUpSkin(Skin skin, float skin_float);
	
	Skin getSkin() const;
	float getSkinFloat() const;
	float getPrice() const;
	int getVolume() const;
	std::string getWear() const;
	std::string getSkinName() const;


private:
	Skin skin;
	std::string skinName;
	std::string wear;
	float skin_float;
	float price = 0.0f;
	int volume = 0;
	void fetchMarketPrice();
	std::string convertFloatToWear() const;



};

