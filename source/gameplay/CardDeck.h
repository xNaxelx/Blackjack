#pragma once
#include "../gameplay/Card.h"
#include "../engine/UpdateSystem.h"
#include <vector>
#include <algorithm>
#include <random>


class CardDeck
{
public:
	CardDeck(int positionX, int positionY, std::vector<Card*> allCards, UpdateSystem* updateSystem);
	SDL_Rect GetPosition();

	Card* PickupCard(int x, int y);
	void ThrowCardToTrash(Card* card);
	void MixDeck();
	void RestoreDeck();

	std::string skinPackName;
private:
	SDL_Rect deckPosition;
	std::vector<Card*> cardsInDeck;
	SDL_Rect trashPosition;
	std::vector<Card*> cardsInTrash;
};

