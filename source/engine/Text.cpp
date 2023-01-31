#include "Text.h"

Text::Text(const char* file, int ptsize, int x, int y, std::string text, SDL_Renderer* renderer)
{
	this->x = x;
	this->y = y;
	font = TTF_OpenFont(file, ptsize);
	PrepareTextureFromText(text, font, SDL_Color{ 240, 240, 240 }, renderer);
}

void Text::UpdateTexture(SDL_Renderer* renderer)
{
	Render(x, y, renderer);
}

void Text::ChangeText(std::string newText, SDL_Renderer* renderer)
{
	PrepareTextureFromText(newText, font, SDL_Color{ 240, 240, 240 }, renderer);
}