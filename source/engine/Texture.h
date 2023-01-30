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
	std::vector<SDL_Rect> spriteClips;

	Texture();
	~Texture();

	bool LoadFromFile(std::string path, SDL_Renderer* renderer, int positionX, int positionY, int framesCount, int width, int heigth);
	bool LoadFromRenderedText(std::string textureText, TTF_Font* font, SDL_Color textColor, SDL_Renderer* renderer);
	virtual void Render(int x, int y, SDL_Renderer* renderer, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);


	int getWidth();
	int getHeight();
private:
	int delay = 0;
	std::unique_ptr<SDL_Texture, void (*)(SDL_Texture*)> texture;
	//SDL_Rect textureBox;

	void Free();

	int positionX = 0, positionY = 0;
};

