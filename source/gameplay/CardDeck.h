#pragma once
#include "../gameplay/Card.h"
#include "../engine/UpdateSystem.h"
#include "vector"


class CardDeck
{
public:
	CardDeck(int positionX, int positionY, std::vector<Card*> allCards, UpdateSystem* updateSystem);
	SDL_Rect GetPosition();

	void PickupCard();
	void MixDeck();
	void RestoreDeck();

	std::string skinPackName;
private:
	SDL_Rect deckPosition;
	std::vector<Card*> cardsInDeck;
	SDL_Rect trashPosition;
	std::vector<Card*> cardsInTrash;
};

