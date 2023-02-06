#pragma once

#include "../engine/GameObject.h"
#include "../engine/Text.h"
#include "CardDeck.h"
#include "../engine/UpdateSystem.h"
#include <vector>


class Participant : public GameObject
{
public:
	Participant(int x, int y, SDL_Renderer* renderer, Time* timer, CardDeck* deck, UpdateSystem* updateSystem);
	void Hit();
	void Stand();
	
	bool isFinishHitting = false, permisionToTurn = false;
protected:
	void ChangeScore(int score);

	SDL_Renderer* renderer;
	UpdateSystem* updateSystem;
	Text* scoreText;
	CardDeck* deck;
	std::vector<Card*> cards;
	int scoreInt = 0, balance;
	int participantID;
	bool haveAce = false;	
};

