#include "Croupier.h"

Croupier::Croupier(int x, int y, SDL_Renderer* renderer, Time* timer, CardDeck* deck, UpdateSystem* updateSystem)
	: Participant(x, y, renderer, timer, deck, updateSystem)
{
	isFinishHitting = false;
	permisionToTurn = true;

	Hit();
	Hit();
	cards.back()->showShirt = true;
	scoreText->ChangeText(std::to_string(cards.front()->GetRank() <= 10 ? cards.front()->GetRank() : 10) + " + ?", renderer);

	permisionToTurn = false;
}

void Croupier::Play()
{
	
	if (scoreInt < 14)
	{
		Hit();
	}

	isFinishHitting = true;
	permisionToTurn = false;

	cards.back()->showShirt = false;
	scoreText->ChangeText(std::to_string(scoreInt), renderer);
}

void Croupier::NewRound()
{
	isFinishHitting = false;
	permisionToTurn = true;

	for (Card* card : cards)
	{
		deck->ThrowCardToTrash(card);
	}
	cards.clear();
	scoreInt = 0;

	Hit();
	Hit();

	cards.back()->showShirt = true;
	scoreText->ChangeText(std::to_string(cards.front()->GetRank() <= 10 ? cards.front()->GetRank() : 10) + " + ?", renderer);

	permisionToTurn = false;
}