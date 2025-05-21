#pragma once
#ifndef TRADEUP_H
#define TRADEUP_H
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>
#include <vector>
#include <array>
#include "TradeUpSkin.h"
#include "../CS/Skins.h"
#include "../CS/Rarity.h"
class TradeUp {
public:
	TradeUp(std::array<TradeUpSkin, 10> skins, const Skins& allSkins);
	std::string getTradeUpId() {
		return this->id;
	}

private:
	std::string id;
	Skins allSkins;
	RarityEnum tradeUpInputRarity;
	RarityEnum tradeUpOutputRarity;
	std::array<TradeUpSkin, 10> skins;
	float averageFloat;
	float tradeUpCost;
	float profitability;
	float profit;
	float oddsToProfit;
	std::vector<TradeUpSkin> outcomes;

	std::string createId() const;
	float calculateAverageFloat() const;
	float calculateProfitability() const;
	float calculateProfit() const;
	float oddsToProfit() const;
	std::vector<TradeUpSkin> calculateOutComes();
	RarityEnum getInputRarity();
};

#endif