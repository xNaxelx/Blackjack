#include "CardDeck.h"

CardDeck::CardDeck(int positionX, int positionY, std::vector<Card*> allCards, UpdateSystem* updateSystem)
{
	deckPosition.x = positionX;
	deckPosition.y = positionY;
	trashPosition.x = deckPosition.x;
	trashPosition.y = deckPosition.y + 500;

	cardsInDeck = allCards;
	MixDeck();
	for (auto card : cardsInDeck)
	{
		card->SetPosition(deckPosition.x, deckPosition.y);
	}
}

Card* CardDeck::PickupCard(int x, int y)
{
	Card* temp = cardsInDeck.back();
	cardsInDeck.pop_back();
	temp->MoveTo(x, y);
	temp->showShirt = false;
	return temp;
}

void CardDeck::ThrowCardToTrash(Card* card)
{
	cardsInTrash.push_back(card);
	card->MoveTo(trashPosition.x, trashPosition.y);
}
void CardDeck::MixDeck()
{
	/*std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(cardsInDeck.begin(), cardsInDeck.end(), g);*/

	
}