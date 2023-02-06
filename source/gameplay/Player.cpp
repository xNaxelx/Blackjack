#include "Player.h"

Player::Player(int x, int y, SDL_Renderer* renderer, Time* timer, CardDeck* deck, UpdateSystem* updateSystem)
	: Participant(x, y, renderer, timer, deck, updateSystem)
{
	balance = 1000;
	isFinishHitting = false;
	permisionToTurn = true;

	balanceText = new Text("resource/Font/Mona-Sans.ttf", 24, transform.x - 400, transform.y, std::to_string(balance), renderer);
	betSizeText = new Text("resource/Font/Mona-Sans.ttf", 24, transform.x - 400, transform.y - 100, std::to_string(betSize), renderer);
	updateSystem->Attach(balanceText);
	updateSystem->Attach(betSizeText);

	Hit();
	Hit();
}

void Player::Bet()
{
	betAccepted = true;
}
void Player::BetIncrease10()
{
	ChangeBet(10);
}

void Player::BetDecrease10()
{
	ChangeBet(-10);
}

void Player::ChangeBet(int changeSize)
{
	if (betSize + changeSize > balance || betSize + changeSize < 0 || betAccepted)
	{
		return;
	}
	betSize += changeSize;
	betSizeText->ChangeText(std::to_string(betSize), renderer);
}

void Player::Win()
{
	balance += betSize;
	isFinishHitting = false;
	permisionToTurn = true;
}

void Player::Lose()
{
	balance -= betSize;
	if (balance <= 0)
	{
		return;
	}
	isFinishHitting = false;
	permisionToTurn = true;
}