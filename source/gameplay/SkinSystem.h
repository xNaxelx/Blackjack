#pragma once

#include <boost/filesystem.hpp>
#include <string>
#include <vector>
#include "Card.h"
#include "../engine/UpdateSystem.h"


class SkinSystem
{
public:
	SkinSystem();
	SkinSystem(std::string pathToSkinDirectory, std::string pathToShirtSkinDirectory, SDL_Renderer* renderer, Time* timer, UpdateSystem* updateSystem);

	

	bool ShowSkins();
	bool ShowShirtSkins();

	bool ChangeSkins();
	bool ChangeShirtSkins();

	std::vector<Card*>* GetAllCardsVector();
private:
	void LoadCards(SDL_Renderer* renderer, Time* timer);


	std::string pathToSkinDirectory;
	std::string pathToShirtSkinDirectory;

	std::vector<Card*> allCards;
};

// for (directory_entry& x : directory_iterator(p)) { } 