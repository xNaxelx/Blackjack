#include "SkinSystem.h"

SkinSystem::SkinSystem()
{

}

SkinSystem::SkinSystem(std::string pathToSkinDirectory, std::string pathToShirtSkinDirectory, SDL_Renderer* renderer, Time* timer, UpdateSystem* updateSystem)
{
	this->pathToSkinDirectory = pathToSkinDirectory;
	this->pathToShirtSkinDirectory = pathToShirtSkinDirectory;
	this->renderer = renderer;

	Card::SetShirtTexture(pathToShirtSkinDirectory + "/" + curentShirtSkinID, renderer, 1, 188, 291);
	LoadCards(renderer, timer);
	
	std::vector<Card*>::iterator iterator = allCards.begin();
	for (int i = 0; iterator != allCards.end(); iterator++, i++)
	{
		updateSystem->Attach((*iterator));
	}
}

std::vector<Card*>* SkinSystem::GetAllCardsVector()
{
	return &allCards;
}
#include <iostream>
void SkinSystem::LoadCards(SDL_Renderer* renderer, Time* timer)
{
	allCards.resize(0);

	for (int suitID = 0; suitID < cardSuitNames.size(); suitID++)
	{
		for (int rankID = 0; rankID < cardRankNames.size(); rankID++)
		{
			if (rankID == 0) 
			{
				allCards.push_back(new Card((Suit)(suitID + 1), (CardRank)(rankID + 1), -500, -500, 1, 188, 291, pathToSkinDirectory + "/" + currentSkinsID + "/" + cardSuitNames[suitID] + cardRankNames[rankID] + ".png", renderer, timer));
			}
			else if (rankID > 0)
			{
				allCards.push_back(new Card((Suit)(suitID + 1), (CardRank)(rankID + 5), -500, -500, 1, 188, 291, pathToSkinDirectory + "/" + currentSkinsID + "/" + cardSuitNames[suitID] + cardRankNames[rankID] + ".png", renderer, timer));
			}
		}
	}	
}

void SkinSystem::ChangeSkins()
{
	int tempDirectoryCount = 0;
	std::string tempDirectoryCountString;
	for(boost::filesystem::directory_entry& entry : boost::filesystem::directory_iterator(pathToSkinDirectory));
	{
		tempDirectoryCount++;
	}
	tempDirectoryCountString = std::to_string(tempDirectoryCount);
	boost::filesystem::directory_iterator iterator(pathToSkinDirectory);
	for (boost::filesystem::directory_entry& entry : iterator) 
	{
		if (entry.path().filename().string() == currentSkinsID)
		{
			if (entry.path().filename().string() == tempDirectoryCountString)
			{
				iterator = boost::filesystem::directory_iterator(pathToSkinDirectory);
				break;
			}
			else
			{
				iterator++;
				break;
			}
		}
	}
	currentSkinsID = iterator->path().filename().string();
	for (auto deckIterator : allCards)
	{
		if (deckIterator->GetRank() == 1)
		{
			std::cout << pathToSkinDirectory + "/" + currentSkinsID + "/" + cardSuitNames[deckIterator->GetSuit() - 1] + cardRankNames[deckIterator->GetRank() - 1] + ".png" << std::endl;
			deckIterator->ChangeSkinTexture(pathToSkinDirectory + "/" + currentSkinsID + "/" + cardSuitNames[deckIterator->GetSuit() - 1] + cardRankNames[deckIterator->GetRank() - 1] + ".png", renderer, 1, 188, 291);
		}
		else if (deckIterator->GetRank() >= 6)
		{
			std::cout << pathToSkinDirectory + "/" + currentSkinsID + "/" + cardSuitNames[deckIterator->GetSuit() - 1] + cardRankNames[deckIterator->GetRank() - 5] + ".png" << std::endl;
			deckIterator->ChangeSkinTexture(pathToSkinDirectory + "/" + currentSkinsID + "/" + cardSuitNames[deckIterator->GetSuit() - 1] + cardRankNames[deckIterator->GetRank() - 5] + ".png", renderer, 1, 188, 291);
		}
	}
}
// for (directory_entry& x : directory_iterator(p)) { } 
void SkinSystem::ChangeShirtSkins()
{
	int tempShirtCount = 0;
	std::string tempShirtCountString;
	for (boost::filesystem::directory_entry& entry : boost::filesystem::directory_iterator(pathToShirtSkinDirectory))
	{
		tempShirtCount++;
	}
	tempShirtCountString = std::to_string(tempShirtCount);
	boost::filesystem::directory_iterator iterator(pathToShirtSkinDirectory);
	for (boost::filesystem::directory_entry& entry : iterator)
	{
		if (entry.path().filename().string() == curentShirtSkinID)
		{
			if (entry.path().filename().string() == tempShirtCountString + ".png")
			{
				iterator = boost::filesystem::directory_iterator(pathToShirtSkinDirectory);
				break;
			}
			else
			{
				iterator++;
				break;
			}
		}
	}
	curentShirtSkinID = iterator->path().filename().string();

	std::cout << pathToShirtSkinDirectory + "/" + curentShirtSkinID << std::endl;
	Card::ChangeShirtTexture(pathToShirtSkinDirectory + "/" + curentShirtSkinID, renderer, 1, 188, 291);
}