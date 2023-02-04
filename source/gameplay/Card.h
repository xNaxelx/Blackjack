#pragma once
#include "../engine/GameObject.h"

enum Suit
{
	SUIT_NOT_INITIALISED = 0,
	CARD_SUIT_CLUB,
	CARD_SUIT_DIAMOND,
	CARD_SUIT_HEART,
	CARD_SUIT_SPADE
};

enum CardRank 
{
	RANK_NOT_INITIALISED = 0,
	CARD_RANK_6 = 6,
	CARD_RANK_7 = 7,
	CARD_RANK_8 = 8,
	CARD_RANK_9 = 9,
	CARD_RANK_10 = 10,
	CARD_RANK_JACK = 10,
	CARD_RANK_QUEEN = 10,
	CARD_RANK_KING = 10,
	CARD_RANK_ACE = 11
};

class Card : public GameObject
{
public:
	Card(Suit suit, CardRank rank, int x, int y, int animFramesCount, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer);
	
	void RenderTexture(SDL_Renderer* renderer) override;
	void UpdateMove() override;

	static void SetShirtTexture(std::string path, SDL_Renderer* renderer, int animationTilesCount, int width, int heigth);

	Suit GetSuit();
	CardRank GetRank();
	bool showShirt = true;
private:
	static Texture* shirtTexture;

	Suit suit = SUIT_NOT_INITIALISED;
	CardRank rank = RANK_NOT_INITIALISED;
};

