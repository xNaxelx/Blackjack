#include "Player.h"

Player::Player(int x, int y, SDL_Renderer* renderer, Time* timer, CardDeck* deck, UpdateSystem* updateSystem)
	: Participant(x, y, renderer, timer, deck, updateSystem)
{
	balance = 1000;
	isFinishHitting = false;
	permisionToTurn = true;

	balanceText = new Text("resource/Font/Mona-Sans.ttf", 24, transform.x - 100, transform.y + 100, std::to_string(balance), renderer);
	betSizeText = new Text("resource/Font/Mona-Sans.ttf", 24, transform.x - 100, transform.y + 150, std::to_string(betSize), renderer);
	updateSystem->Attach(balanceText);
	updateSystem->Attach(betSizeText);

	Hit();
	Hit();

	permisionToTurn = false;
}

void Player::Bet()
{
	if (isFinishHitting == true || permisionToTurn == true)
	{
		return;
	}
	betAccepted = true;
	permisionToTurn = true;

	printf("Bet\n");
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
	balanceText->ChangeText(std::to_string(balance), renderer);
}

void Player::Lose()
{
	balance -= betSize;
	if (balance <= 0)
	{
		return;
	}
	balanceText->ChangeText(std::to_string(balance), renderer);
}

void Player::NewRound()
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

	permisionToTurn = false;
	betAccepted = false;
}