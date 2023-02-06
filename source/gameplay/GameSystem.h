#pragma once

#include "Player.h"
#include "Croupier.h"
#include "../engine/Button.h"


class GameSystem
{
public:
	GameSystem() {};
	GameSystem(Player* player, Croupier* croupier, Button* continiueButton);

	void CheckIfPlayerFinish();

	void ButtonFunctional();	
private:
	void CheckIfRoundFinish();
	

	Player* player;
	Croupier* croupier;
	Button* continiueButton;

	bool blockGame = false;
};

