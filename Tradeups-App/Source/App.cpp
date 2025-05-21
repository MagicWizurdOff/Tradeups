#include <iostream>
#include <fstream> 
#include <vector>
#include "Core/Core.h"
#include "Core/TradeUps/SteamAPI.h"
#include "Core/CS/Skins.h"
#include "Core/CS/FilterType.h"
#include <Core/TradeUps/TradeUpSkin.h>
#include <Core/TradeUps/TradeUp.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	Skins skins("skins.json");
	Skin skin(skins.id("skin-9db642f7226bbbf0c55864b7260db49de589f895").getFirst());

	std::array<TradeUpSkin, 10> tradeUpSkins{};
	for (int i = 0; i < 10; i++) {
		tradeUpSkins[i] = TradeUpSkin(skin, 0.12f);
	}
	TradeUp tradeUp(tradeUpSkins, skins);

	std::cout << tradeUp.getTradeUpId() << std::endl;

	/*while (true) {
		FilterType filterType;
		std::string stringFilterType;
		std::string search;
		std::cout << "Type in the type of filter you want to use:" << std::endl;
		std::cin >> stringFilterType;
		filterType = getFilterType(stringFilterType);
		std::cout << "Search the value:" << std::endl;
		std::cin >> search;

		std::vector<Skin> query = skins.where(filterType, search);
		
		for (Skin skin : query) {
			TradeUpSkin tradeUpSkin(skin, 0.05);
			std::cout << "Price for skin " << tradeUpSkin.getSkin().getName() << ": " << tradeUpSkin.getPrice() << "€"
				<< " with volume of " << tradeUpSkin.getVolume() << std::endl;
			Sleep(3000);
		}
	}*/

}
