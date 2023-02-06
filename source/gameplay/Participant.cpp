#include "Participant.h"

Participant::Participant(int x, int y, SDL_Renderer* renderer, Time* timer, CardDeck* deck, UpdateSystem* updateSystem) :
	GameObject(x, y, 0, 0, 0, "\0", renderer, timer)
{
	this->deck = deck;
	this->renderer = renderer;
	this->updateSystem = updateSystem;
	scoreText = new Text("resource/Font/Mona-Sans.ttf", 24, transform.x - 200, transform.y, "0", renderer);
	updateSystem->Attach(scoreText);
}

void Participant::Hit()
{
	if (isFinishHitting || !permisionToTurn)
	{
		return;
	}
	cards.push_back(deck->PickupCard(transform.x + 200 * cards.size(), transform.y));
	cards.back()->showShirt = false;
	if (cards.back()->GetRank() >= CARD_RANK_6 && cards.back()->GetRank() <= CARD_RANK_10)
	{
		ChangeScore(cards.back()->GetRank());
	}
	else if(cards.back()->GetRank() == CARD_RANK_JACK || cards.back()->GetRank() == CARD_RANK_QUEEN || cards.back()->GetRank() == CARD_RANK_KING)
	{
		ChangeScore(10);
	}
	else if (cards.back()->GetRank() == CARD_RANK_ACE)
	{
		haveAce = true;
		ChangeScore(11);
	}
}

void Participant::Stand()
{
	isFinishHitting = true;
	permisionToTurn = false;
	updateSystem->NotifyTurnEnd(participantID);
}

void Participant::ChangeScore(int score)
{
	if (score != 0)
	{
		scoreInt += score;
	}
	else
	{
		scoreInt = 0;
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