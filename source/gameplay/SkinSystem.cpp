#include "SkinSystem.h"

SkinSystem::SkinSystem()
{

}

SkinSystem::SkinSystem(std::string pathToSkinDirectory, std::string pathToShirtSkinDirectory, SDL_Renderer* renderer, Time* timer, UpdateSystem* updateSystem)
{
	this->pathToSkinDirectory = pathToSkinDirectory;
	this->pathToShirtSkinDirectory = pathToShirtSkinDirectory;

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

void SkinSystem::LoadCards(SDL_Renderer* renderer, Time* timer)
{
	allCards.resize(0);

	allCards.push_back(new Card(CARD_SUIT_CLUB, CARD_RANK_ACE, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Club01.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_CLUB, CARD_RANK_6, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Club06.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_CLUB, CARD_RANK_7, -500, -500, 1, 188, 291, pathToSkinDirectory + "//1/Club07.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_CLUB, CARD_RANK_8, -500, -500, 1, 188, 291, pathToSkinDirectory + "//1/Club08.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_CLUB, CARD_RANK_9, -500, -500, 1, 188, 291, pathToSkinDirectory + "//1/Club09.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_CLUB, CARD_RANK_10, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Club10.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_CLUB, CARD_RANK_JACK, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Club11.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_CLUB, CARD_RANK_QUEEN, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Club12.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_CLUB, CARD_RANK_KING, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Club13.png", renderer, timer));

	allCards.push_back(new Card(CARD_SUIT_DIAMOND, CARD_RANK_ACE, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Diamond01.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_DIAMOND, CARD_RANK_6, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Diamond06.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_DIAMOND, CARD_RANK_7, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Diamond07.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_DIAMOND, CARD_RANK_8, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Diamond08.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_DIAMOND, CARD_RANK_9, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Diamond09.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_DIAMOND, CARD_RANK_10, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Diamond10.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_DIAMOND, CARD_RANK_JACK, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Diamond11.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_DIAMOND, CARD_RANK_QUEEN, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Diamond12.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_DIAMOND, CARD_RANK_KING, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Diamond13.png", renderer, timer));

	allCards.push_back(new Card(CARD_SUIT_HEART, CARD_RANK_ACE, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Heart01.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_HEART, CARD_RANK_6, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Heart06.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_HEART, CARD_RANK_7, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Heart07.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_HEART, CARD_RANK_8, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Heart08.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_HEART, CARD_RANK_9, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Heart09.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_HEART, CARD_RANK_10, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Heart10.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_HEART, CARD_RANK_JACK, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Heart11.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_HEART, CARD_RANK_QUEEN, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Heart12.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_HEART, CARD_RANK_KING, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Heart13.png", renderer, timer));

	allCards.push_back(new Card(CARD_SUIT_SPADE, CARD_RANK_ACE, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Spade01.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_SPADE, CARD_RANK_6, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Spade06.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_SPADE, CARD_RANK_7, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Spade07.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_SPADE, CARD_RANK_8, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Spade08.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_SPADE, CARD_RANK_9, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Spade09.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_SPADE, CARD_RANK_10, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Spade10.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_SPADE, CARD_RANK_JACK, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Spade11.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_SPADE, CARD_RANK_QUEEN, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Spade12.png", renderer, timer));
	allCards.push_back(new Card(CARD_SUIT_SPADE, CARD_RANK_KING, -500, -500, 1, 188, 291, pathToSkinDirectory + "/1/Spade13.png", renderer, timer));

	
}