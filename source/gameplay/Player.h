#pragma once

#include "Participant.h"


class Player : public Participant
{
public:
	Player(int x, int y, SDL_Renderer* renderer, Time* timer, CardDeck* deck, UpdateSystem* updateSystem);

	void Bet();
	void BetIncrease10();
	void BetDecrease10();
	
	void Win();
	void Lose();
private:
	void ChangeBet(int changeSize);

	Text* balanceText, *betSizeText;
	int betSize = 10;
	bool betAccepted = false;
};

