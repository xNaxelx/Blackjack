#pragma once

#include "Participant.h"


class Croupier : public Participant
{
public:
	Croupier(int x, int y, SDL_Renderer* renderer, Time* timer, CardDeck* deck, UpdateSystem* updateSystem);
private:
	
};

