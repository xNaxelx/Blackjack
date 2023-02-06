#include "Participant.h"

Participant::Participant(int x, int y, SDL_Renderer* renderer, Time* timer, CardDeck* deck, UpdateSystem* updateSystem) :
	GameObject(x, y, 0, 0, 0, "\0", renderer, timer)
{
	this->deck = deck;
	this->renderer = renderer;
	this->updateSystem = updateSystem;
	scoreText = new Text("resource/Font/Mona-Sans.ttf", 24, transform.x - 100, transform.y, "0", renderer);
	updateSystem->Attach(scoreText);
}

int Participant::GetScore()
{
	return scoreInt;
}

void Participant::Hit()
{
	if (isFinishHitting || !permisionToTurn)
	{
		return;
	}
	cards.push_back(deck->PickupCard(transform.x + 200 * cards.size(), transform.y));
	cards.back()->showShirt = false;

	ChangeScore(cards.back()->GetRank());

	printf("Hit\n");
}

void Participant::Stand()
{
	if (isFinishHitting == true || permisionToTurn == false)
	{
		return;
	}
	isFinishHitting = true;
	permisionToTurn = false;

	printf("Stand\n");
}

void Participant::ChangeScore(CardRank rank)
{
	if (rank == RANK_NOT_INITIALISED)
	{
		scoreInt = -100;
		printf("BUG: Participant::ChangeScore(RANK_NOT_INITIALISED)\n");
		return;
	}
	else if (rank == 0)
	{
		scoreInt = 0;
	}
	else if (rank >= CARD_RANK_6 && rank <= CARD_RANK_10)
	{
		scoreInt += rank;
	}
	else if (rank == CARD_RANK_JACK || rank == CARD_RANK_QUEEN || rank == CARD_RANK_KING)
	{
		scoreInt += 10;
	}
	else if (cards.back()->GetRank() == CARD_RANK_ACE)
	{
		haveAce = true;
		scoreInt += 11;
	}
	else
	{
		printf("BUG: Participant::ChangeScore(incorrect input)");
		return;
	}

	if (scoreInt > 21 && haveAce)
	{
		scoreInt -= 10;
		haveAce = false;
	}
	scoreText->ChangeText(std::to_string(scoreInt), renderer);
	if (scoreInt > 21)
	{
		Stand();
	}
}