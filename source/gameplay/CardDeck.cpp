#include "CardDeck.h"

CardDeck::CardDeck(int positionX, int positionY, std::vector<Card*> allCards, UpdateSystem* updateSystem)
{
	deckPosition.x = positionX;
	deckPosition.y = positionY;
	trashPosition.x = deckPosition.x;
	trashPosition.y = deckPosition.y + 500;

	cardsInDeck = allCards;
	std::vector<Card*>::iterator iterator = cardsInDeck.begin();
	for (int i = 0; iterator != cardsInDeck.end(); iterator++, i++)
	{
		(*iterator)->SetPosition(deckPosition.x + i, deckPosition.y - i);
	}
}