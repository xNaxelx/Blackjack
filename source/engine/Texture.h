#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <memory>

class Texture
{
public:
	

	Texture();
	~Texture();

	bool LoadTextureFromFile(std::string path, SDL_Renderer* renderer, int positionX, int positionY, int animationTilesCount, int width, int heigth);
	bool PrepareTextureFromText(std::string textureText, TTF_Font* font, SDL_Color textColor, SDL_Renderer* renderer);
	virtual void Render(int x, int y, SDL_Renderer* renderer, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);


	int getWidth();
	int getHeight();
private:
	int delay = 0;
	unsigned int animationTilesCount = 1, currentAnimationTile = 1;
	SDL_Texture* texture;
	std::vector<SDL_Rect> tilesRectangle;



	void Free();

	int positionX = 0, positionY = 0;
};

