#include "Croupier.h"

Croupier::Croupier(int x, int y, SDL_Renderer* renderer, Time* timer, CardDeck* deck, UpdateSystem* updateSystem)
	: Participant(x, y, renderer, timer, deck, updateSystem)
{
	isFinishHitting = false;
	permisionToTurn = true;

	Hit();
	Hit();
	cards.back()->showShirt = true;
	scoreText->ChangeText(std::to_string(cards.front()->GetRank()) + " + ?", renderer);

	permisionToTurn = false;
}