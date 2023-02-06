#include "CardDeck.h"


CardDeck::CardDeck(int positionX, int positionY, std::vector<Card*> allCards, UpdateSystem* updateSystem)
{
	deckPosition.x = positionX;
	deckPosition.y = positionY;
	trashPosition.x = deckPosition.x;
	trashPosition.y = deckPosition.y + 400;

	cardsInDeck = allCards;
	MixDeck();
	for (auto card : cardsInDeck)
	{
		card->SetPosition(deckPosition.x, deckPosition.y);
	}
}

Card* CardDeck::PickupCard(int x, int y)
{
	if (cardsInDeck.empty())
	{
		RestoreDeck();
	}
	Card* temp = cardsInDeck.back();
	temp->MoveTo(x, y);
	cardsInDeck.pop_back();
	return temp;
}

void CardDeck::ThrowCardToTrash(Card* card)
{
	cardsInTrash.push_back(card);
	card->MoveTo(trashPosition.x, trashPosition.y);
	card->showShirt = false;
}

void CardDeck::MixDeck()
{
	std::shuffle(cardsInDeck.begin(), cardsInDeck.end(), std::mt19937{ std::random_device{}() });
	
}

void CardDeck::RestoreDeck()
{
	for (Card* card : cardsInTrash)
	{
		card->MoveTo(deckPosition.x, deckPosition.y);
		cardsInDeck.push_back(card);
		card->showShirt = true;
	}
	cardsInTrash.clear();
}