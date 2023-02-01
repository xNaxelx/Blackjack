#include "Card.h"

Card::Card(Suit suit, CardRank rank, int x, int y, int animFramesCount, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer)
	: GameObject(x, y, animFramesCount, width, height, texturePath, renderer, timer)
{
	this->suit = suit;
	this->rank = rank;
}

void Card::RenderTexture(SDL_Renderer* renderer)
{
	if (showShirt)
	{
		shirt->Render(transform.x, transform.y, renderer);
	}
	else
	{
		texture->Render(transform.x, transform.y, renderer);
	}
}

void Card::SetShirtTexture(std::string path, SDL_Renderer* renderer, int animationTilesCount, int width, int heigth)
{
	if (shirt != NULL)
	{
		shirt->~Texture();
	}
	shirt = new Texture();
	shirt->LoadTextureFromFile(path, renderer, animationTilesCount, width, heigth);
}

Suit Card::GetSuit()
{
	return suit;
}

CardRank Card::GetRank()
{
	return rank;
}

Texture* Card::shirt = NULL;