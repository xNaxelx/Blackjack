#include "GameSystem.h"


GameSystem::GameSystem(Player* player, Croupier* croupier, Button* continiueButton)
{
	this->player = player;
	this->croupier = croupier;
	this->continiueButton = continiueButton;
	continiueButton->isHiden = true;
}

void GameSystem::CheckIfPlayerFinish()
{
	if (player->isFinishHitting && continiueButton->isHiden == true)
	{
		if (player->GetScore() > 21)
		{
			player->Lose();

		}
		else
		{
			croupier->Play();

			if (player->GetScore() > croupier->GetScore())
			{
				player->Win();
			}
			else if (player->GetScore() == croupier->GetScore())
			{

			}
			else if (player->GetScore() < croupier->GetScore())
			{
				player->Lose();
			}
		}

		
		continiueButton->isHiden = false;
	}
}

void GameSystem::ButtonFunctional()
{
	player->NewRound();
	croupier->NewRound();

	continiueButton->isHiden = true;
}