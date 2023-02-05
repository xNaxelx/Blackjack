#pragma once

#include <boost/filesystem.hpp>
#include <string>
#include <vector>
#include "Card.h"
#include "../engine/UpdateSystem.h"

static std::vector<std::string> cardSuitNames
{
	"Club", "Diamond", "Heart", "Spade"
};

static std::vector<std::string> cardRankNames
{
	"01", "06", "07", "08", "09", "10", "11", "12", "13"
};

class SkinSystem
{
public:
	SkinSystem();
	SkinSystem(std::string pathToSkinDirectory, std::string pathToShirtSkinDirectory, SDL_Renderer* renderer, Time* timer, UpdateSystem* updateSystem);

	std::vector<Card*>* GetAllCardsVector();

	void ChangeSkins();
	void ChangeShirtSkins();
private:
	void LoadCards(SDL_Renderer* renderer, Time* timer);

	std::string currentSkinsID = "0";
	std::string curentShirtSkinID = "1.png";

	std::string pathToSkinDirectory;
	std::string pathToShirtSkinDirectory;

	std::vector<Card*> allCards;

	SDL_Renderer* renderer;
};

