#pragma once

#include "Texture.h"
#include "Observer.h"
#include <SDL.h>
#include <SDL_ttf.h>

class Text : public Texture, public IObserver
{
public:
	Text(const char* file, int ptsize, int x, int y, std::string text, SDL_Renderer* renderer);

	void RenderTexture(SDL_Renderer* renderer);

	void ChangeText(std::string newText, SDL_Renderer* renderer);

private:
	TTF_Font* font;
	int x = 0;
	int y = 0;
};

